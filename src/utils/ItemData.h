#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <wx/clntdata.h>
#include <wx/filename.h>

class ItemData : public wxClientData {
public:
    ItemData(const wxFileName& info)
        : m_info(info) {}

    wxFileName GetInfo() const { return m_info; }
    wxUIntPtr GetData() const { return reinterpret_cast<wxUIntPtr>(this); }

private:
    wxFileName m_info;
};

#endif  // ITEMDATA_H