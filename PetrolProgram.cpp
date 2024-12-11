#include <wx/wx.h>
#include "MainFrame.h"

class PetrolProgram : public wxApp {
public:
	bool OnInit() override;
};

bool PetrolProgram::OnInit() {
    MainFrame* mainFrame = new MainFrame("");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}

wxIMPLEMENT_APP(PetrolProgram);




