#ifndef FILEINFO_H
#define FILEINFO_H

#include <wx/filename.h>
#include <wx/timer.h>
#include <functional>

struct FileInfo {
    enum class CallbackType {
        INTERVAL,
        CHANGED
    };
    wxFileName file;
    wxTimer timer;
    wxString content    = wxEmptyString;
    wxString html       = wxEmptyString;
    bool contentChanged = false;  // whether the content has changed by the user in the editor
    wxEvtHandler* owner = nullptr;

    std::function<void(wxFileName, FileInfo::CallbackType)> callback = nullptr;

    wxDateTime lastModified;

    FileInfo(const wxFileName& file, wxEvtHandler* parentEvt)
        : file(file), owner(parentEvt) {
        this->lastModified = file.GetModificationTime();
        timer.Bind(wxEVT_TIMER, [this](wxTimerEvent& event) {
            if (this->file.Exists() == false) {
                return;
            }
            if (this->file.GetModificationTime() > this->lastModified) {
                this->lastModified = this->file.GetModificationTime();
                if (this->callback) {
                    this->callback(this->file, CallbackType::CHANGED);
                }
            } else {
                if (this->callback) {
                    this->callback(this->file, CallbackType::INTERVAL);
                }
            }
        });
    }

    void SetCallback(std::function<void(wxFileName, FileInfo::CallbackType)> cb) {
        if (cb) {
            this->callback = cb;
            if (this->timer.IsRunning() == false) {
                this->Start();
            }
        }
    }

    void Start(int interval = 1000) {
        timer.Start(interval);
    }
    void Stop() {
        timer.Stop();
    }

    wxString GetTimeAgo() {
        return wxString::Format(_("%s"), FormatTimeAgo(this->lastModified));
    }
    const wxString FormatTimeAgo(const wxDateTime& lastModified) {
        wxDateTime now  = wxDateTime::Now();
        wxTimeSpan diff = now - lastModified;

        if (diff.GetMinutes() < 1) {
            return _("just now");
        } else if (diff.GetMinutes() < 60) {
            if (diff.GetMinutes() == 1) {
                return _("1 minute ago");
            }
            return wxString::Format(_("%d minute(s) ago"), diff.GetMinutes());
        } else {
            return lastModified.Format(_("%Y-%m-%d %H:%M"));
        }
    }
};

#endif  // FILEINFO_H
