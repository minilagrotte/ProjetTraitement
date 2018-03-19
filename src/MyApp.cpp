#include "MyApp.h"
#include "MyFrame.h"
#include "FrameOutil.h"

bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame( wxT("Application Badass"), wxPoint(50, 50), wxSize(450, 340) );
	FrameOutil *frameOutil = new FrameOutil(wxT("Outil de l'application Badass"),wxPoint(0,0),wxSize(300,500));
	wxInitAllImageHandlers();
	frame->Show(true);
	frameOutil->Show(true);
	return true;
}



IMPLEMENT_APP(MyApp)
