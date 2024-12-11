#include <wx/wx.h>
#include "MainFrame.h"

class MyApp : public wxApp
{
public:
	bool OnInit() override;
};

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show();
    return true;
}



wxIMPLEMENT_APP(MyApp);




