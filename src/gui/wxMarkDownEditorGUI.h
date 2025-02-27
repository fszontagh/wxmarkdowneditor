///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/cshelp.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/dataview.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stc/stc.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/splitter.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class mainFrame
///////////////////////////////////////////////////////////////////////////////
class mainFrame : public wxFrame
{
	private:

	protected:
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel4;
		wxDataViewListCtrl* m_currentOpenFiles;
		wxDataViewColumn* m_dataViewListColumn1;
		wxDataViewColumn* m_dataViewListColumn2;
		wxPanel* m_panel5;
		wxNotebook* m_notebook1;
		wxPanel* MarkDownPanel;
		wxStyledTextCtrl* editor;
		wxPanel* m_panel3;
		wxStatusBar* m_statusBar1;
		wxMenuBar* mainMenuBar;
		wxMenu* fileMenu;

		// Virtual event handlers, override them in your derived class
		virtual void OnSplitterSashPositionChanged( wxSplitterEvent& event ) { event.Skip(); }
		virtual void OnOpenFileActivated( wxDataViewEvent& event ) { event.Skip(); }
		virtual void OnEditorChar( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnEditorKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnEditorKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxBoxSizer* bSizer4;

		mainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Markdown Master"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~mainFrame();

		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 1 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( mainFrame::m_splitter1OnIdle ), NULL, this );
		}

};

