#include "LLDBCallStack.h"
#include "LLDBEvent.h"
#include "LLDBDebugger.h"

LLDBCallStackPane::LLDBCallStackPane(wxWindow* parent, LLDBDebugger* lldb)
    : LLDBCallStackBase(parent)
    , m_lldb(lldb)
{
    m_lldb->Bind(wxEVT_LLDB_BACKTRACE, &LLDBCallStackPane::OnBacktrace, this);
    m_lldb->Bind(wxEVT_LLDB_RUNNING, &LLDBCallStackPane::OnRunning, this);
}

LLDBCallStackPane::~LLDBCallStackPane()
{
    m_lldb->Unbind(wxEVT_LLDB_BACKTRACE, &LLDBCallStackPane::OnBacktrace, this);
    m_lldb->Unbind(wxEVT_LLDB_RUNNING, &LLDBCallStackPane::OnRunning, this);
}

void LLDBCallStackPane::OnBacktrace(LLDBEvent& event)
{
    event.Skip();
    m_dvListCtrlBacktrace->DeleteAllItems();
    const LLDBBacktrace& bt = event.GetBacktrace();
    const LLDBBacktrace::EntryVec_t& entries =  bt.GetCallstack();
    for(size_t i=0; i<entries.size(); ++i) {
        wxVector<wxVariant> cols;
        const LLDBBacktrace::Entry& entry = entries.at(i);
        cols.push_back( entry.id );
        cols.push_back( entry.functionName );
        cols.push_back( entry.filename );
        cols.push_back( entry.line + 1 );
        m_dvListCtrlBacktrace->AppendItem(cols);
    }
}

void LLDBCallStackPane::OnRunning(LLDBEvent& event)
{
    event.Skip();
    m_dvListCtrlBacktrace->DeleteAllItems();
}
