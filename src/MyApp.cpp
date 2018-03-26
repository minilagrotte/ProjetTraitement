#include "MyApp.h"

#include "FrameColorPicker.h"

bool MyApp::OnInit()
{

	frame = new MyFrame( wxT("Application Badass"), wxPoint(50, 50), wxSize(450, 340),this );
	frameOutil = new FrameOutil(wxT("Outil de l'application Badass"),wxPoint(0,0),wxSize(300,500),this);

	wxInitAllImageHandlers();
	frame->Show(true);
    frameOutil->InitButton();
	frameOutil->Show(true);

	return true;
}

void MyApp::action(wxCommandEvent& event)
{
    frame->OnProcess(event);
}


IMPLEMENT_APP(MyApp)
