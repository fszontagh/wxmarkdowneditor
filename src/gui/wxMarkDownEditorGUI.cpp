///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxMarkDownEditorGUI.h"

// Using the construction of a static object to ensure that the help provider is set
// wx Manages the most recent HelpProvider passed to ::Set, but not the previous ones
// If ::Set gets called more than once, the previous one is returned and should be deleted
class wxFBContextSensitiveHelpSetter
{
public:
wxFBContextSensitiveHelpSetter()
{
wxSimpleHelpProvider* help = new wxSimpleHelpProvider();
wxHelpProvider* old = wxHelpProvider::Set( help );
if (old != 0){
delete old;
}
}
};

static wxFBContextSensitiveHelpSetter s_wxFBSetTheHelpProvider;
///////////////////////////////////////////////////////////////////////////

mainFrame::mainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxBORDER_NONE );
	m_splitter1->SetSashGravity( 0.5 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( mainFrame::m_splitter1OnIdle ), NULL, this );
	m_splitter1->SetMinimumPaneSize( 200 );

	m_panel4 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( m_panel4, wxID_ANY, _("Open Files"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer5->Add( m_staticText1, 0, wxALL|wxEXPAND, 5 );

	m_currentOpenFiles = new wxDataViewListCtrl( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_ROW_LINES );
	m_dataViewListColumn1 = m_currentOpenFiles->AppendTextColumn( _("Name"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_LEFT), wxDATAVIEW_COL_RESIZABLE );
	m_dataViewListColumn2 = m_currentOpenFiles->AppendTextColumn( _("Last Modified"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_LEFT), wxDATAVIEW_COL_RESIZABLE );
	bSizer5->Add( m_currentOpenFiles, 1, wxALL|wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer5 );
	m_panel4->Layout();
	bSizer5->Fit( m_panel4 );
	m_panel5 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	MarkDownPanel = new wxPanel( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxTAB_TRAVERSAL, wxT("TabMarkdown") );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	editor = new wxStyledTextCtrl( MarkDownPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	editor->SetUseTabs( true );
	editor->SetTabWidth( 4 );
	editor->SetIndent( 4 );
	editor->SetTabIndents( true );
	editor->SetBackSpaceUnIndents( true );
	editor->SetViewEOL( false );
	editor->SetViewWhiteSpace( false );
	editor->SetMarginWidth( 2, 0 );
	editor->SetIndentationGuides( true );
	editor->SetReadOnly( false );
	editor->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	editor->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	editor->SetMarginWidth( 1, 16);
	editor->SetMarginSensitive( 1, true );
	editor->SetProperty( wxT("fold"), wxT("1") );
	editor->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	editor->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	editor->SetMarginWidth( 0, editor->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	editor->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	editor->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	editor->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	editor->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	editor->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	editor->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	editor->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	editor->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	editor->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	editor->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	editor->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	editor->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	editor->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	editor->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	editor->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	editor->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	editor->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	editor->Hide();

	bSizer2->Add( editor, 1, wxEXPAND | wxALL, 5 );


	MarkDownPanel->SetSizer( bSizer2 );
	MarkDownPanel->Layout();
	bSizer2->Fit( MarkDownPanel );
	bSizer7->Add( MarkDownPanel, 1, wxEXPAND | wxALL, 0 );

	m_panel3 = new wxPanel( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxTAB_TRAVERSAL, wxT("TabHtml") );
	bSizer4 = new wxBoxSizer( wxVERTICAL );


	m_panel3->SetSizer( bSizer4 );
	m_panel3->Layout();
	bSizer4->Fit( m_panel3 );
	bSizer7->Add( m_panel3, 1, wxEXPAND | wxALL, 0 );


	m_panel5->SetSizer( bSizer7 );
	m_panel5->Layout();
	bSizer7->Fit( m_panel5 );
	m_splitter1->SplitVertically( m_panel4, m_panel5, 1 );
	bSizer1->Add( m_splitter1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	mainMenuBar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* m_newFile;
	m_newFile = new wxMenuItem( fileMenu, wxID_NEW, wxString( _("&New") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_newFile->SetBitmaps( wxNullBitmap, wxArtProvider::GetBitmap( wxASCII_STR(wxART_NEW), wxASCII_STR(wxART_MENU) ) );
	#endif
	fileMenu->Append( m_newFile );

	fileMenu->AppendSeparator();

	wxMenuItem* m_openFile;
	m_openFile = new wxMenuItem( fileMenu, wxID_OPEN, wxString( _("&Open") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_openFile->SetBitmaps( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_MENU) ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_openFile->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_MENU) ) );
	#endif
	fileMenu->Append( m_openFile );

	m_open_recent = new wxMenu();
	wxMenuItem* m_open_recentItem = new wxMenuItem( fileMenu, wxID_ANY, _("Open &recent..."), wxEmptyString, wxITEM_NORMAL, m_open_recent );
	#if (defined( __WXMSW__ ) || defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_open_recentItem->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_MENU) ) );
	#endif

	fileMenu->Append( m_open_recentItem );

	fileMenu->AppendSeparator();

	wxMenuItem* m_save;
	m_save = new wxMenuItem( fileMenu, wxID_SAVE, wxString( _("&Save") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_save->SetBitmaps( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_SAVE), wxASCII_STR(wxART_MENU) ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_save->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_SAVE), wxASCII_STR(wxART_MENU) ) );
	#endif
	fileMenu->Append( m_save );

	wxMenuItem* m_saveAs;
	m_saveAs = new wxMenuItem( fileMenu, wxID_SAVEAS, wxString( _("S&ave as...") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_saveAs->SetBitmaps( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_SAVE_AS), wxASCII_STR(wxART_MENU) ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_saveAs->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_SAVE_AS), wxASCII_STR(wxART_MENU) ) );
	#endif
	fileMenu->Append( m_saveAs );

	fileMenu->AppendSeparator();

	wxMenuItem* m_menuExit;
	m_menuExit = new wxMenuItem( fileMenu, wxID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuExit->SetBitmaps( wxArtProvider::GetBitmap( wxASCII_STR(wxART_QUIT), wxASCII_STR(wxART_MENU) ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuExit->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_QUIT), wxASCII_STR(wxART_MENU) ) );
	#endif
	fileMenu->Append( m_menuExit );

	mainMenuBar->Append( fileMenu, _("&File") );

	this->SetMenuBar( mainMenuBar );


	this->Centre( wxBOTH );

	// Connect Events
	m_splitter1->Connect( wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED, wxSplitterEventHandler( mainFrame::OnSplitterSashPositionChanged ), NULL, this );
	m_currentOpenFiles->Connect( wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler( mainFrame::OnOpenFileActivated ), NULL, this );
	editor->Connect( wxEVT_CHAR, wxKeyEventHandler( mainFrame::OnEditorChar ), NULL, this );
	editor->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( mainFrame::OnEditorKeyDown ), NULL, this );
	editor->Connect( wxEVT_KEY_UP, wxKeyEventHandler( mainFrame::OnEditorKeyUp ), NULL, this );
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnNew ), this, m_newFile->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnOpen ), this, m_openFile->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnSave ), this, m_save->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnSaveAs ), this, m_saveAs->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnExit ), this, m_menuExit->GetId());
}

mainFrame::~mainFrame()
{
}
