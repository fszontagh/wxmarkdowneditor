#ifndef PREVIEWUPDATETHREAD_H
#define PREVIEWUPDATETHREAD_H
#include <wx/event.h>
#include <wx/thread.h>
#include <atomic>

wxDEFINE_EVENT(EVT_UPDATE_PREVIEW, wxCommandEvent);

class PreviewUpdateThread : public wxThread {
private:
    wxEvtHandler* eventHandler;
    std::atomic<bool> updateRequested{false};

public:
    PreviewUpdateThread(wxEvtHandler* handler)
        : wxThread(wxTHREAD_DETACHED), eventHandler(handler) {}

    void RequestUpdate() {
        updateRequested = true;
    }

    virtual ExitCode Entry() override {
        while (!TestDestroy()) {
            if (updateRequested.exchange(false)) {
                wxCommandEvent event(EVT_UPDATE_PREVIEW);
                wxPostEvent(eventHandler, event);
            }
            wxThread::Sleep(500);
        }
        return 0;
    }
};

#endif  // PREVIEWUPDATETHREAD_H