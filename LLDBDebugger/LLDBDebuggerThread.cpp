#include "LLDBDebuggerThread.h"
#include "LLDBDebugger.h"
#include "file_logger.h"

LLDBDebuggerThread::LLDBDebuggerThread(LLDBDebugger* owner, lldb::SBListener listener, lldb::SBProcess process)
    : wxThread(wxTHREAD_JOINABLE)
    , m_owner(owner)
    , m_listener(listener)
    , m_process(process)
{
}

LLDBDebuggerThread::~LLDBDebuggerThread()
{
    if ( IsAlive() ) {
        Delete(NULL, wxTHREAD_WAIT_BLOCK);
    } else {
        Wait(wxTHREAD_WAIT_BLOCK);
    }
}

void* LLDBDebuggerThread::Entry()
{
    bool first_time_stopped = true;
    while ( !TestDestroy() ) {
        lldb::SBEvent event;
        if ( m_listener.WaitForEvent(1, event) && event.IsValid() ) {
            lldb::StateType state = m_process.GetStateFromEvent( event );
            switch ( state ) {
            case lldb::eStateStopped: 
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, true );
                if ( first_time_stopped ) {
                    first_time_stopped = false;
                    CL_DEBUG("LLDBDebuggerThread: eStateStopped - first time");
                    m_owner->CallAfter( &LLDBDebugger::NotifyStoppedOnFirstEntry );
                    
                } else {
                    CL_DEBUG("LLDBDebuggerThread: eStateStopped");
                    m_owner->CallAfter( &LLDBDebugger::NotifyBacktrace );
                    m_owner->CallAfter( &LLDBDebugger::NotifyStopped );
                    
                }
                break;

            case lldb::eStateConnected:
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, true );
                CL_DEBUG("LLDBDebuggerThread: eStateConnected");
                break;

            case lldb::eStateLaunching:
                CL_DEBUG("LLDBDebuggerThread: eStateLaunching");
                break;

            case lldb::eStateRunning:
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, false );
                m_owner->CallAfter( &LLDBDebugger::NotifyRunning );
                CL_DEBUG("LLDBDebuggerThread: eStateRunning");
                break;

            case lldb::eStateExited:
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, true );
                CL_DEBUG("LLDBDebuggerThread: eStateExited");
                m_owner->CallAfter( &LLDBDebugger::NotifyExited );
                break;
                
            case lldb::eStateAttaching:
                CL_DEBUG("LLDBDebuggerThread: eStateExited");
                break;
                
            case lldb::eStateStepping:
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, true );
                CL_DEBUG("LLDBDebuggerThread: eStateStepping");
                break;
                
            case lldb::eStateCrashed:
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, true );
                CL_DEBUG("LLDBDebuggerThread: eStateCrashed");
                break;
                
            case lldb::eStateDetached:
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, false );
                CL_DEBUG("LLDBDebuggerThread: eStateDetached");
                break;
                
            case lldb::eStateSuspended:
                m_owner->CallAfter( &LLDBDebugger::SetCanInteract, false );
                CL_DEBUG("LLDBDebuggerThread: eStateSuspended");
                break;
            }
        }
    }
    return NULL;
}
