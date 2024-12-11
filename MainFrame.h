#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

enum {
    ID_Hello = 1
};

//Need to make MainFrame.cpp but idc
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, "Petrol Program") {
    //button shit. Panel because stretched child
    wxPanel* panel = new wxPanel(this);
    //ToDo: make easy way to change position. Might have to learn more todo    
    wxButton* Menu = new wxButton(panel, wxID_ANY, "Menu", wxPoint(125, 10), wxSize(100, 35));
    wxButton* Login = new wxButton(panel, wxID_ANY, "Login in", wxPoint(125, 50), wxSize(100, 35));

    wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "Petrol", wxPoint(125, 100));

    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "AAAAAAAAAA", wxPoint(125, 150));

    wxTextCtrl* TextCtrl = new wxTextCtrl(panel, wxID_ANY, "OEOOAOAOF", wxPoint(250, 50), wxSize(200, -1));

    wxSlider* slider = new wxSlider(panel, wxID_ANY, 50, 0, 100, wxPoint(250, 100), wxSize(200, -1));

    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(250, 10), wxSize(200, -1));
    gauge->SetValue(50);

    wxArrayString choices;
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");

    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(250, 150), wxSize(100, -1), choices);
    choice->Select(2);

    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(250, 200), wxSize(100, -1));

    wxListBox* ListBox = new wxListBox(panel, wxID_ANY, wxPoint(250, 250), wxSize(100, -1), choices); 

    wxRadioBox* RadioBox = new wxRadioBox(panel, wxID_ANY, "Diesel", wxPoint(250, 300), wxDefaultSize, choices);

    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl+H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Welcome to my Petrol Program!");
}
