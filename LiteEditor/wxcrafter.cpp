#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC3F25InitBitmapResources();

static bool bBitmapLoaded = false;


NewProjectDlgBaseClass::NewProjectDlgBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    m_splitter5 = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME|wxSP_3DSASH);
    m_splitter5->SetSashGravity(0.000000);
    m_splitter5->SetMinimumPaneSize(10);
    
    boxSizer1->Add(m_splitter5, 1, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_splitterPageRight = new wxPanel(m_splitter5, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* boxSizer10 = new wxBoxSizer(wxVERTICAL);
    m_splitterPageRight->SetSizer(boxSizer10);
    
    m_staticText34 = new wxStaticText(m_splitterPageRight, wxID_ANY, _("Project category:"), wxDefaultPosition, wxSize(-1,-1), 0);wxFont m_staticText34Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText34Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText34->SetFont(m_staticText34Font);
    
    boxSizer10->Add(m_staticText34, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    
    wxArrayString m_chCategoriesArr;
    m_chCategories = new wxChoice(m_splitterPageRight, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_chCategoriesArr, 0);
    
    boxSizer10->Add(m_chCategories, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_listTemplates = new wxListCtrl(m_splitterPageRight, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLC_SINGLE_SEL|wxLC_REPORT);
    
    boxSizer10->Add(m_listTemplates, 1, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_listTemplates->InsertColumn(m_listTemplates->GetColumnCount(), _("Template:"), wxLIST_FORMAT_LEFT, -1);
    m_splitterPageLeft = new wxPanel(m_splitter5, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_splitter5->SplitVertically(m_splitterPageRight, m_splitterPageLeft, 150);
    
    wxBoxSizer* boxSizer11 = new wxBoxSizer(wxVERTICAL);
    m_splitterPageLeft->SetSizer(boxSizer11);
    
    wxFlexGridSizer* flexGridSizer15 = new wxFlexGridSizer(  0, 2, 0, 0);
    flexGridSizer15->SetFlexibleDirection( wxBOTH );
    flexGridSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer15->AddGrowableCol(1);
    
    boxSizer11->Add(flexGridSizer15, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_staticText16 = new wxStaticText(m_splitterPageLeft, wxID_ANY, _("Project name:"), wxDefaultPosition, wxSize(-1,-1), 0);wxFont m_staticText16Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText16Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText16->SetFont(m_staticText16Font);
    
    flexGridSizer15->Add(m_staticText16, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_txtProjName = new wxTextCtrl(m_splitterPageLeft, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_RICH2);
    
    flexGridSizer15->Add(m_txtProjName, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_staticText18 = new wxStaticText(m_splitterPageLeft, wxID_ANY, _("Project path:"), wxDefaultPosition, wxSize(-1,-1), 0);wxFont m_staticText18Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText18Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText18->SetFont(m_staticText18Font);
    
    flexGridSizer15->Add(m_staticText18, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxBoxSizer* boxSizer30 = new wxBoxSizer(wxHORIZONTAL);
    
    flexGridSizer15->Add(boxSizer30, 0, wxEXPAND, 5);
    
    m_textCtrlProjectPath = new wxTextCtrl(m_splitterPageLeft, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_RICH2);
    
    boxSizer30->Add(m_textCtrlProjectPath, 1, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5);
    
    m_bmpButton33 = new wxBitmapButton(m_splitterPageLeft, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("find-folder")), wxDefaultPosition, wxSize(40,-1), wxBU_AUTODRAW);
    
    boxSizer30->Add(m_bmpButton33, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM, 5);
    
    m_staticText21 = new wxStaticText(m_splitterPageLeft, wxID_ANY, _("Compiler:"), wxDefaultPosition, wxSize(-1,-1), 0);wxFont m_staticText21Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText21Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText21->SetFont(m_staticText21Font);
    
    flexGridSizer15->Add(m_staticText21, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxArrayString m_chCompilerArr;
    m_chCompiler = new wxChoice(m_splitterPageLeft, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_chCompilerArr, 0);
    
    flexGridSizer15->Add(m_chCompiler, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    wxStaticBoxSizer* statixBoxSizer24 = new wxStaticBoxSizer( new wxStaticBox(m_splitterPageLeft, wxID_ANY, _("Project file:")), wxVERTICAL);
    
    boxSizer11->Add(statixBoxSizer24, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_cbSeparateDir = new wxCheckBox(m_splitterPageLeft, wxID_ANY, _("Create the project under a separate directory"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_cbSeparateDir->SetValue(false);
    
    statixBoxSizer24->Add(m_cbSeparateDir, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_stxtFullFileName = new wxStaticText(m_splitterPageLeft, wxID_ANY, _(""), wxDefaultPosition, wxSize(-1,-1), 0);
    statixBoxSizer24->Add(m_stxtFullFileName, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    wxStaticBoxSizer* statixBoxSizer28 = new wxStaticBoxSizer( new wxStaticBox(m_splitterPageLeft, wxID_ANY, _("Description:")), wxVERTICAL);
    
    boxSizer11->Add(statixBoxSizer28, 1, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_txtDescription = new wxTextCtrl(m_splitterPageLeft, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_RICH2|wxTE_READONLY|wxTE_MULTILINE);
    m_txtDescription->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    
    statixBoxSizer28->Add(m_txtDescription, 1, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer1->Add(boxSizer2, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button3 = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_button3->SetDefault();
    
    boxSizer2->Add(m_button3, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM, 5);
    
    m_button4 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer2->Add(m_button4, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM, 5);
    
    
    GetSizer()->Fit(this);
    Centre();
    // Connect events
    m_chCategories->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(NewProjectDlgBaseClass::OnCategorySelected), NULL, this);
    m_listTemplates->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(NewProjectDlgBaseClass::OnTemplateSelected), NULL, this);
    m_txtProjName->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(NewProjectDlgBaseClass::OnProjectNameChanged), NULL, this);
    m_textCtrlProjectPath->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(NewProjectDlgBaseClass::OnProjectPathUpdated), NULL, this);
    m_bmpButton33->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NewProjectDlgBaseClass::OnBrowseProjectPath), NULL, this);
    m_cbSeparateDir->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(NewProjectDlgBaseClass::OnProjectNameChanged), NULL, this);
    m_button3->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(NewProjectDlgBaseClass::OnOKUI), NULL, this);
    
}

NewProjectDlgBaseClass::~NewProjectDlgBaseClass()
{
    m_chCategories->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(NewProjectDlgBaseClass::OnCategorySelected), NULL, this);
    m_listTemplates->Disconnect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(NewProjectDlgBaseClass::OnTemplateSelected), NULL, this);
    m_txtProjName->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(NewProjectDlgBaseClass::OnProjectNameChanged), NULL, this);
    m_textCtrlProjectPath->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(NewProjectDlgBaseClass::OnProjectPathUpdated), NULL, this);
    m_bmpButton33->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NewProjectDlgBaseClass::OnBrowseProjectPath), NULL, this);
    m_cbSeparateDir->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(NewProjectDlgBaseClass::OnProjectNameChanged), NULL, this);
    m_button3->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(NewProjectDlgBaseClass::OnOKUI), NULL, this);
    
}