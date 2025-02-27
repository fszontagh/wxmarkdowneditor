#include <wx/wx.h>
#include <wx/stc/stc.h>
#include "wxMarkDownEditormainFrame.h"
#include "icons/logo_64.png.h"

class wxMDEditor : public wxApp {
public:
    virtual bool OnInit() {
        wxInitAllImageHandlers();
        //wxConfig *config = new wxConfig("wxMarkDownEditor");
        wxMarkDownEditormainFrame* frame = new wxMarkDownEditormainFrame(nullptr);
        frame->SetIcon(logo_64_png_to_wx_icon());
        frame->ShowWithEffect(wxSHOW_EFFECT_BLEND, 6000);
        //frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(wxMDEditor);
