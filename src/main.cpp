#include <wx/stc/stc.h>
#include <wx/wx.h>
#include "icons/logo_64.png.h"
#include "wxMarkDownEditormainFrame.h"

class wxMDEditor : public wxApp {
    wxLocale m_locale;
    wxConfig* m_config;

public:
    virtual bool OnInit() {
        wxInitAllImageHandlers();

        m_locale.Init(wxLANGUAGE_DEFAULT);
        wxApp::SetAppName(wxT("wxMarkdownEditor"));
        wxApp::SetAppDisplayName(wxT("wxMarkdown Editor"));

        m_config = new wxConfig();
        wxConfig::Set(m_config);

        wxMarkDownEditormainFrame* frame = new wxMarkDownEditormainFrame(nullptr, this->m_config);
        frame->SetIcon(logo_64_png_to_wx_icon());
        frame->Show(true);
        return true;
    }
    wxConfig* GetConfig() { return m_config; }
};

wxIMPLEMENT_APP(wxMDEditor);
