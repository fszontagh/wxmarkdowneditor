///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxMarkDownEditorGUI.h"

#include "../icons/html_code_16.png.h"
#include "../icons/logo_16.png.h"

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

	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->SetSashGravity( 0.5 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( mainFrame::m_splitter1OnIdle ), NULL, this );
	m_splitter1->SetMinimumPaneSize( 200 );

	m_panel4 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_currentOpenFiles = new wxDataViewListCtrl( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_ROW_LINES );
	m_dataViewListColumn1 = m_currentOpenFiles->AppendTextColumn( _("Name"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_LEFT), wxDATAVIEW_COL_RESIZABLE );
	m_dataViewListColumn2 = m_currentOpenFiles->AppendTextColumn( _("Last Modified"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_LEFT), wxDATAVIEW_COL_RESIZABLE );
	bSizer5->Add( m_currentOpenFiles, 1, wxALL|wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer5 );
	m_panel4->Layout();
	bSizer5->Fit( m_panel4 );
	m_panel5 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_notebook1 = new wxNotebook( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_NOPAGETHEME|wxNB_TOP|wxBORDER_DEFAULT, wxT("notebook1") );
	wxSize m_notebook1ImageSize = wxSize( 16,16 );
	int m_notebook1Index = 0;
	wxImageList* m_notebook1Images = new wxImageList( m_notebook1ImageSize.GetWidth(), m_notebook1ImageSize.GetHeight() );
	m_notebook1->AssignImageList( m_notebook1Images );
	wxBitmap m_notebook1Bitmap;
	wxImage m_notebook1Image;
	MarkDownPanel = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT("TabMarkdown") );
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
	bSizer2->Add( editor, 1, wxEXPAND | wxALL, 5 );


	MarkDownPanel->SetSizer( bSizer2 );
	MarkDownPanel->Layout();
	bSizer2->Fit( MarkDownPanel );
	m_notebook1->AddPage( MarkDownPanel, _("MarkDown"), true );
	m_notebook1Bitmap = logo_16_png_to_wx_bitmap();
	if ( m_notebook1Bitmap.Ok() )
	{
		m_notebook1Image = m_notebook1Bitmap.ConvertToImage();
		m_notebook1Images->Add( m_notebook1Image.Scale( m_notebook1ImageSize.GetWidth(), m_notebook1ImageSize.GetHeight() ) );
		m_notebook1->SetPageImage( m_notebook1Index, m_notebook1Index );
		m_notebook1Index++;
	}
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT("TabHtml") );
	bSizer4 = new wxBoxSizer( wxVERTICAL );


	m_panel3->SetSizer( bSizer4 );
	m_panel3->Layout();
	bSizer4->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, _("Preview"), false );
	m_notebook1Bitmap = html_code_16_png_to_wx_bitmap();
	if ( m_notebook1Bitmap.Ok() )
	{
		m_notebook1Image = m_notebook1Bitmap.ConvertToImage();
		m_notebook1Images->Add( m_notebook1Image.Scale( m_notebook1ImageSize.GetWidth(), m_notebook1ImageSize.GetHeight() ) );
		m_notebook1->SetPageImage( m_notebook1Index, m_notebook1Index );
		m_notebook1Index++;
	}

	bSizer7->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );


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
	wxMenuItem* m_openFile;
	m_openFile = new wxMenuItem( fileMenu, wxID_OPEN, wxString( _("&Open") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_openFile->SetBitmaps( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_MENU) ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_openFile->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_MENU) ) );
	#endif
	fileMenu->Append( m_openFile );

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
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnOpen ), this, m_openFile->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnSave ), this, m_save->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnSaveAs ), this, m_saveAs->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::OnExit ), this, m_menuExit->GetId());
}

mainFrame::~mainFrame()
{
}
