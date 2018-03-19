#include "MyApp.h"
#include "MyFrame.h"

bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame( wxT("Hello World"), wxPoint(50, 50), wxSize(450, 340) );
	wxInitAllImageHandlers();
	frame->Show(true);
	return true;
}



IMPLEMENT_APP(MyApp)
