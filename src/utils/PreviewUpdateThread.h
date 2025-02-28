#ifndef PREVIEWUPDATETHREAD_H
#define PREVIEWUPDATETHREAD_H
#include <wx/event.h>
#include <atomic>
#include <chrono>
#include <thread>

wxDEFINE_EVENT(EVT_UPDATE_PREVIEW, wxCommandEvent);

class PreviewUpdateThread {
private:
    wxEvtHandler* eventHandler;
    std::atomic<bool> updateRequested{false};
    std::atomic<bool> threadRunning{false};
    std::thread workerThread;

    // A szál végrehajtó funkciója
    void ThreadEntry() {
        while (threadRunning) {
            if (updateRequested.exchange(false)) {
                wxCommandEvent event(EVT_UPDATE_PREVIEW);
                wxPostEvent(eventHandler, event);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

public:
    PreviewUpdateThread(wxEvtHandler* handler)
        : eventHandler(handler) {}

    void Start() {
        if (!threadRunning) {
            threadRunning = true;
            workerThread  = std::thread(&PreviewUpdateThread::ThreadEntry, this);
        }
    }

    void Stop() {
        if (threadRunning) {
            threadRunning = false;
            if (workerThread.joinable()) {
                workerThread.join();
            }
        }
    }

    void RequestUpdate() {
        updateRequested = true;
    }

    ~PreviewUpdateThread() {
        Stop();
    }
};

#endif  // PREVIEWUPDATETHREAD_H
