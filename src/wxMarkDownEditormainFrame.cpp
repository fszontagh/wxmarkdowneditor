#include "wxMarkDownEditormainFrame.h"
#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <wx/stdpaths.h>

#include "gui/defaultCss.h"
#include "utils/ItemData.h"

wxMarkDownEditormainFrame::wxMarkDownEditormainFrame(wxWindow* parent)
    : mainFrame(parent) {
    this->config = new wxConfig("wxMarkDownEditor");

    this->webView = wxWebView::New(m_panel3, wxID_ANY, "about:blank", wxDefaultPosition, wxDefaultSize);
    this->webView->Connect(wxEVT_WEBVIEW_NAVIGATING, wxWebViewEventHandler(wxMarkDownEditormainFrame::OnWebViewNavigating), nullptr, this);

    // webView->LoadURL("file:///path/to/your/html/file.html");

    // htmlPreview = new wxHtmlWindow( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
    this->bSizer4->Add(this->webView, 1, wxALL | wxEXPAND, 5);

    // Set lexer for markdown syntax
    this->editor->SetLexer(wxSTC_LEX_MARKDOWN);
    this->editor->SetWrapMode(wxSTC_WRAP_WORD);
    this->editor->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);

    // Format headers
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_HEADER1, *wxRED);
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_HEADER2, *wxBLUE);
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_HEADER3, *wxGREEN);

    // Format code blocks
    this->editor->StyleSetBackground(wxSTC_MARKDOWN_CODE, *wxLIGHT_GREY);
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_CODE, *wxBLACK);

    // Format italic and bold text
    this->editor->StyleSetBold(wxSTC_MARKDOWN_EM1, true);    // Italic text
    this->editor->StyleSetItalic(wxSTC_MARKDOWN_EM2, true);  // Bold text

    // Format links
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_LINK, *wxBLUE);
    this->editor->StyleSetUnderline(wxSTC_MARKDOWN_LINK, true);  // Underlined links

    // Format list items
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_OLIST_ITEM, *wxBLACK);
    this->editor->StyleSetBackground(wxSTC_MARKDOWN_OLIST_ITEM, *wxLIGHT_GREY);

    this->editor->StyleSetForeground(wxSTC_MARKDOWN_ULIST_ITEM, *wxBLACK);
    this->editor->StyleSetBackground(wxSTC_MARKDOWN_ULIST_ITEM, *wxLIGHT_GREY);

    // Format normal text (default)
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_DEFAULT, *wxBLACK);

    // Other custom formatting
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_BLOCKQUOTE, wxColour(128, 128, 128));  // Grey color for blockquote

    // prepare the parser
    this->parserConfig = std::make_shared<maddy::ParserConfig>();
    // config->isEmphasizedParserEnabled = false; // default true - this flag is deprecated
    // config->isHTMLWrappedInParagraph = false; // default true - this flag is deprecated
    // this->parserConfig->enabledParsers &= ~maddy::types::EMPHASIZED_PARSER;  // equivalent to !isEmphasizedParserEnabled
    this->parserConfig->enabledParsers |= maddy::types::HTML_PARSER;  // equivalent to !isHTMLWrappedInParagraph

    this->parser     = std::make_shared<maddy::Parser>(this->parserConfig);
    auto splitterPos = this->config->Read("/SplitterPosition/m_splitter1", 300);
    this->m_splitter1->SetSashPosition(splitterPos);

    auto cfg = wxStandardPaths::Get().GetUserDataDir();
    if (!wxDirExists(cfg)) {
        wxMkdir(cfg);
    }
    wxFileName configFilePath(cfg, "wxMarkDownEditorThemes.ini");
    this->CreateDefaultConfigFile(configFilePath.GetFullPath());

    // prepare the update thread
    Bind(EVT_UPDATE_PREVIEW, &wxMarkDownEditormainFrame::OnUpdatePreview, this);
    updateThread = new PreviewUpdateThread(this);
    if (updateThread->Run() != wxTHREAD_NO_ERROR) {
        wxLogError("Nem sikerült elindítani az előnézet frissítő szálat!");
        delete updateThread;
        updateThread = nullptr;
    }
}

wxMarkDownEditormainFrame::~wxMarkDownEditormainFrame() {
    if (updateThread) {
        updateThread->Delete();
        delete updateThread;
        updateThread = nullptr;
    }
    this->config->Write("/SplitterPosition/m_splitter1", this->m_splitter1->GetSashPosition());

    for (auto olditem : this->historyMenuItems) {
        this->m_open_recent->Remove(olditem);
        delete olditem;
    }
    this->historyMenuItems.clear();

    delete this->config;
}
void wxMarkDownEditormainFrame::OnEditorChar(wxKeyEvent& event) {
    // this->UpdatePreview();
    // this->RequestPreviewUpdate();
    event.Skip();
}

void wxMarkDownEditormainFrame::OnEditorKeyDown(wxKeyEvent& event) {
    // this->UpdatePreview();
    this->RequestPreviewUpdate();
    event.Skip();
}

void wxMarkDownEditormainFrame::OnEditorKeyUp(wxKeyEvent& event) {
    // this->UpdatePreview();
    // this->RequestPreviewUpdate();
    event.Skip();
}

/*void wxMarkDownEditormainFrame::OnHtmlLinkClicked(wxHtmlLinkEvent& event) {
    wxString url = event.GetLinkInfo().GetHref();
    wxString msg = wxString::Format(_("Do you want to open this URL?\n%s"), url);
    if (wxMessageBox(msg, _("Open URL"), wxYES_NO | wxICON_QUESTION) == wxYES) {
        wxLaunchDefaultBrowser(url);
    }
}*/

void wxMarkDownEditormainFrame::OnOpen(wxCommandEvent& event) {
    wxString filename = wxFileSelector(_("Open File"), wxEmptyString, wxEmptyString, wxEmptyString, _("Markdown Files (*.md)|*.md"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    this->OpenFile(filename);
}
void wxMarkDownEditormainFrame::OnExit(wxCommandEvent& event) {
    Close();
}
void wxMarkDownEditormainFrame::OnNew(wxCommandEvent& event) {
    auto dir = wxStandardPaths::Get().GetUserDir(wxStandardPaths::Dir::Dir_Documents);
    wxFileName emptyFile(dir, _("untitled"));
    emptyFile.SetExt("md");

    int c = 1;
    while (wxFileExists(emptyFile.GetFullPath())) {
        emptyFile.SetName(wxString::Format(_("untitled%d"), c++));
    }

    wxString filter   = _("Markdown Files (*.md)|*.md");
    wxString filename = wxFileSelector(_("Save File As"), emptyFile.GetPath(), emptyFile.GetName(), emptyFile.GetExt(), filter, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (!filename.IsEmpty()) {
        wxFile file;
        if (file.Create(filename, true)) {
            file.Close();
            this->OpenFile(filename);
        }
    }
}
void wxMarkDownEditormainFrame::OnSave(wxCommandEvent& event) {
    if (this->currentFile && this->currentFile->contentChanged) {
        wxFile file;
        if (file.Create(this->currentFile->file.GetAbsolutePath(), true)) {
            file.Write(this->currentFile->content);
            file.Close();
            this->currentFile->contentChanged = false;
            wxSetWorkingDirectory(this->currentFile->file.GetPath());
        }
    }
}
void wxMarkDownEditormainFrame::OnSaveAs(wxCommandEvent& event) {
    if (this->currentFile == nullptr) {
        return;
    }
    wxString filter   = _("Markdown Files (*.md)|*.md|HTML Files (*.html)|*.html");
    wxString filename = wxFileSelector(_("Save File As"), this->currentFile->file.GetPath(), this->currentFile->file.GetName(), this->currentFile->file.GetExt(), filter, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (!filename.IsEmpty()) {
        wxFile file;
        if (file.Create(filename, true)) {
            wxFileName fn(filename);
            wxString content;
            if (this->currentFile == nullptr) {
                file.Close();
                return;
            }
            if (fn.GetExt().Lower() == "html") {
                content = this->currentFile->html;
            } else {
                content = this->currentFile->content;
            }
            file.Write(content);
            file.Close();
            this->currentFile->contentChanged = false;
            wxSetWorkingDirectory(this->currentFile->file.GetPath());
        }
    }
}
void wxMarkDownEditormainFrame::UpdatePreview(bool forceUpdate) {
    const auto currentContent = this->editor->GetText();

    if (this->currentFile == nullptr) {
        return;
    }

    if (this->currentFile->content == currentContent && !forceUpdate) {
        return;
    }

    this->currentFile->content = wxString(currentContent);

    /* wxWidgets 3.1.1+ */
    std::stringstream markdownInput(std::string(currentContent.utf8_string()));
    std::string htmlOutput = parser->Parse(markdownInput);
    /* wxWidgets 3.0.4- */
    wxString wxHtmlOutput = wxString::FromUTF8(htmlOutput.c_str());

    wxString cssFilePath = this->currentCssFile;
    wxString cssLink;

    if (!cssFilePath.IsEmpty() && wxFileExists(cssFilePath)) {
        cssLink = "<link rel=\"stylesheet\" type=\"text/css\" href=\"" + cssFilePath + "\" />";
    } else {
        cssLink = "<style type=\"text/css\">" + defaultCss + "</style>";
    }
    this->currentFile->html           = wxString::Format("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"><html><head>%s</head><body>%s</body></html>", cssLink, wxHtmlOutput);
    this->currentFile->contentChanged = true;

    this->webView->SetPage(this->currentFile->html, "file://");

    this->LoadFileHistory();
}
void wxMarkDownEditormainFrame::OnSplitterSashPositionChanged(wxSplitterEvent& event) {
    // this->config->Write("SplitterPosition/m_splitter1", this->m_splitter1->GetSashPosition());
    //  do not save the splitter position here
    event.Skip();
}

void wxMarkDownEditormainFrame::OnOpenFileActivated(wxDataViewEvent& event) {
    auto activatedItem = event.GetItem();
    auto data          = this->m_currentOpenFiles->GetItemData(activatedItem);

    auto filename = reinterpret_cast<ItemData*>(data)->GetInfo();

    if (filename.IsOk() == false) {
        return;
    }

    if (this->files.find(filename.GetAbsolutePath()) == this->files.end()) {
        return;
    }
    if (this->currentFile == this->files.at(filename.GetAbsolutePath())) {
        return;
    }
    this->currentFile = this->files.at(filename.GetAbsolutePath());

    wxString content = this->currentFile->content;
    this->editor->SetText(content);

    // this->UpdatePreview(true);
    this->RequestPreviewUpdate();
    this->SetTitle(this->currentFile->file.GetFullName() + " - wxMarkDownEditor");
}

void wxMarkDownEditormainFrame::LoadStylesFromConfig(const wxString& paletteName) {
    // Létrehozzuk az egyedi config fájl objektumot
    wxConfig* config = new wxConfig("wxMarkDownEditor", "", "path_to_config.ini");

    if (!config) {
        wxLogError("Unable to load configuration.");
        return;
    }

    std::map<wxString, wxColour> colorMap;
    wxString prefix = paletteName + "/";

    colorMap["header1_color"]     = wxColour(config->Read(prefix + "header1_color", "#FF0000"));
    colorMap["header2_color"]     = wxColour(config->Read(prefix + "header2_color", "#0000FF"));
    colorMap["header3_color"]     = wxColour(config->Read(prefix + "header3_color", "#00FF00"));
    colorMap["code_background"]   = wxColour(config->Read(prefix + "code_background", "#D3D3D3"));
    colorMap["code_foreground"]   = wxColour(config->Read(prefix + "code_foreground", "#000000"));
    colorMap["link_color"]        = wxColour(config->Read(prefix + "link_color", "#0000FF"));
    colorMap["list_color"]        = wxColour(config->Read(prefix + "list_color", "#000000"));
    colorMap["quote_color"]       = wxColour(config->Read(prefix + "quote_color", "#A9A9A9"));
    colorMap["normal_text_color"] = wxColour(config->Read(prefix + "normal_text_color", "#000000"));

    this->editor->SetLexer(wxSTC_LEX_MARKDOWN);
    this->editor->SetWrapMode(wxSTC_WRAP_WORD);
    this->editor->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);

    this->editor->StyleSetForeground(wxSTC_MARKDOWN_HEADER1, colorMap["header1_color"]);
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_HEADER2, colorMap["header2_color"]);
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_HEADER3, colorMap["header3_color"]);

    this->editor->StyleSetBackground(wxSTC_MARKDOWN_CODE, colorMap["code_background"]);
    this->editor->StyleSetForeground(wxSTC_MARKDOWN_CODE, colorMap["code_foreground"]);

    this->editor->StyleSetForeground(wxSTC_MARKDOWN_LINK, colorMap["link_color"]);
    this->editor->StyleSetUnderline(wxSTC_MARKDOWN_LINK, true);  // Aláhúzott linkek

    this->editor->StyleSetForeground(wxSTC_MARKDOWN_OLIST_ITEM, colorMap["list_color"]);
    this->editor->StyleSetBackground(wxSTC_MARKDOWN_OLIST_ITEM, colorMap["code_background"]);

    this->editor->StyleSetForeground(wxSTC_MARKDOWN_ULIST_ITEM, colorMap["list_color"]);
    this->editor->StyleSetBackground(wxSTC_MARKDOWN_ULIST_ITEM, colorMap["code_background"]);

    this->editor->StyleSetForeground(wxSTC_MARKDOWN_DEFAULT, colorMap["normal_text_color"]);

    this->editor->StyleSetForeground(wxSTC_MARKDOWN_BLOCKQUOTE, colorMap["quote_color"]);
}
void wxMarkDownEditormainFrame::OnPaletteChange(wxCommandEvent& event) {
    wxString selectedPalette = event.GetString();
    LoadStylesFromConfig(selectedPalette);
}
void wxMarkDownEditormainFrame::CreateDefaultConfigFile(const wxString& configFilePath) {
    wxFileName configFile(configFilePath);
    if (configFile.Exists()) {
        return;
    }

    wxConfig* config = new wxConfig("wxMarkDownEditor", "", configFilePath);
    if (!config) {
        wxLogError("Unable to create configuration.");
        return;
    }
    wxString defaultPalette1 =
        "[Palette1]\n"
        "header1_color = #FF0000\n"
        "header2_color = #0000FF\n"
        "header3_color = #00FF00\n"
        "code_background = #D3D3D3\n"
        "code_foreground = #000000\n"
        "link_color = #0000FF\n"
        "list_color = #000000\n"
        "quote_color = #A9A9A9\n"
        "normal_text_color = #000000\n";

    wxString defaultPalette2 =
        "[Palette2]\n"
        "header1_color = #800080\n"
        "header2_color = #008000\n"
        "header3_color = #FFD700\n"
        "code_background = #FFFFFF\n"
        "code_foreground = #000000\n"
        "link_color = #FF00FF\n"
        "list_color = #0000FF\n"
        "quote_color = #A0A0A0\n"
        "normal_text_color = #000000\n";

    config->Write("Palette1", defaultPalette1);
    config->Write("Palette2", defaultPalette2);
    config->Flush();
}
void wxMarkDownEditormainFrame::OnWebViewNavigating(wxWebViewEvent& event) {
    auto url = event.GetURL();
    std::cout << "Navigating to URL: " << url << std::endl;

    if (url == "file:///") {
        event.Skip();
        return;
    }
    // there is no page loaded
    if (url == "about:blank" || this->currentFile == nullptr) {
        event.Veto();
        return;
    }

    wxString fname = url.SubString(7, url.Len() - 1);
    wxFileName fileName(fname);

    wxString fileWithCurrentDir = fileName.GetFullPath();
    fileWithCurrentDir.Prepend(this->currentFile->file.GetPath() + wxFileName::GetPathSeparator());
    wxFileName fileNameWithCurrentDir(fileWithCurrentDir);

    if (wxFileExists(fileWithCurrentDir) && fileNameWithCurrentDir.GetExt().Lower() == "md") {
        wxMessageDialog dialog(this,
                               wxString::Format("Do you want to open this file?\n%s", fileWithCurrentDir),
                               "Open File",
                               wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);

        if (dialog.ShowModal() == wxID_YES) {
            this->OpenFile(fileWithCurrentDir);
        }

        event.Veto();
        return;
    }

    if (wxFileExists(fileName.GetAbsolutePath())) {
        if (fileName.GetExt().Lower() == "md") {
            wxCommandEvent openEvent(wxEVT_MENU, wxID_OPEN);
            openEvent.SetString(fileName.GetFullPath());
            OnOpen(openEvent);
            return;
        } else {
            event.Skip();
            return;
        }
    }

    if (url.StartsWith("file://")) {
        wxString filePath = url.Mid(7);
        wxFileName fileName(filePath);

        if (!fileName.Exists()) {
            wxMessageDialog dialog(this,
                                   wxString::Format("File not found:\n%s", filePath),
                                   "Error",
                                   wxOK | wxICON_ERROR);
            dialog.ShowModal();
            event.Veto();
            return;
        }

        if (fileName.GetExt().Lower() == "md") {
            wxCommandEvent openEvent(wxEVT_MENU, wxID_OPEN);
            openEvent.SetString(filePath);
            OnOpen(openEvent);
        }
        event.Veto();
    }

    if (url.StartsWith("http://") || url.StartsWith("https://")) {
        wxMessageDialog dialog(this,
                               wxString::Format("Do you want to open this URL?\n%s", url),
                               "Open URL",
                               wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);

        if (dialog.ShowModal() == wxID_YES) {
            wxLaunchDefaultBrowser(url);
        }
        event.Veto();
    }

    event.Veto();
}
void wxMarkDownEditormainFrame::OpenFile(const wxString& fileName) {
    if (!fileName.IsEmpty()) {
        wxFile file;
        if (file.Open(fileName)) {
            wxString content;
            file.ReadAll(&content);
            this->editor->SetText(content);
            file.Close();

            auto info = std::make_shared<FileInfo>(fileName, this->GetEventHandler());
            info->SetCallback(std::bind(&wxMarkDownEditormainFrame::UpdateOpenedFileInfo, this, std::placeholders::_1, std::placeholders::_2));
            this->currentFile                         = info;
            this->files[info->file.GetAbsolutePath()] = std::move(info);

            wxSetWorkingDirectory(this->currentFile->file.GetPath());

            this->config->Write("LastOpenFile", this->currentFile->file.GetFullPath());
            this->config->Write("LastOpenFileDirectory", this->currentFile->file.GetPath());

            wxVector<wxVariant> data;
            data.push_back(wxVariant(this->currentFile->file.GetFullName()));
            data.push_back(wxVariant(this->currentFile->GetTimeAgo()));

            this->m_currentOpenFiles->AppendItem(data);

            auto viewItem = this->m_currentOpenFiles->RowToItem(this->m_currentOpenFiles->GetItemCount() - 1);

            ItemData* itemData = new ItemData(this->currentFile->file);
            this->m_currentOpenFiles->SetItemData(viewItem, itemData->GetData());
            this->m_currentOpenFiles->SetCurrentItem(viewItem);

            // this->UpdatePreview();
            this->RequestPreviewUpdate();
            this->SetTitle(this->currentFile->file.GetFullName() + " - wxMarkDownEditor");
            this->StoreFileHistory(this->currentFile->file.GetAbsolutePath());
        }
    }
}
void wxMarkDownEditormainFrame::UpdateOpenedFileInfo(const wxFileName& file, FileInfo::CallbackType callback) {
    // find the file in the m_currentOpenFiles's items
    for (auto i = this->m_currentOpenFiles->GetItemCount() - 1; i >= 0; i--) {
        auto item = this->m_currentOpenFiles->RowToItem(i);
        if (item.IsOk() == false) {
            continue;
        }
        auto itemData = reinterpret_cast<ItemData*>(this->m_currentOpenFiles->GetItemData(item));
        if (itemData->GetInfo() == file) {
            auto info = this->files[itemData->GetInfo().GetFullPath()];
            if (info == nullptr) {
                continue;
            }

            this->m_currentOpenFiles->SetTextValue(info->GetTimeAgo(), i, 1);
            if (callback == FileInfo::CallbackType::CHANGED) {
                // re-read the file contents and check if differ from the editor's content
                wxString content;
                wxFile file;
                if (file.Open(info->file.GetFullPath())) {
                    file.ReadAll(&content);
                    file.Close();
                    if (content != this->editor->GetText()) {
                        wxMessageDialog dialog(this, "The file has been modified externally. Do you want to load the new content?", "File Changed", wxYES_NO | wxICON_QUESTION);
                        if (dialog.ShowModal() == wxID_YES) {
                            this->editor->SetText(content);
                            // this->UpdatePreview(true);
                            this->RequestPreviewUpdate();
                        }
                    }
                }
            }
            return;
        }
    }
}

void wxMarkDownEditormainFrame::OnThreadMessage(wxThreadEvent& event) {
    wxString message = event.GetString();
}
void wxMarkDownEditormainFrame::LoadFileHistory() {
    if (!config)
        return;

    wxString historyGroup = wxT("/FileHistory");
    config->SetPath(historyGroup);

    fileHistory.clear();
    size_t count = config->ReadLong("Count", 0);

    for (size_t i = 0; i < count; i++) {
        wxString key = wxString::Format("File%zu", i);
        wxString value;
        if (config->Read(key, &value) && wxFileExists(value)) {
            fileHistory.push_back(value);
        }
    }

    config->SetPath(wxT("/"));

    for (auto olditem : this->historyMenuItems) {
        this->m_open_recent->Remove(olditem);
        delete olditem;
    }
    this->historyMenuItems.clear();

    for (const auto file : this->fileHistory) {
        wxMenuItem* menuItem = wxMenuItem::New(this->m_open_recent, wxID_OPEN, file, wxString::Format(_("Open recent file: %s"), file), wxITEM_NORMAL);
        this->historyMenuItems.push_back(std::move(menuItem));
    }
}
m
