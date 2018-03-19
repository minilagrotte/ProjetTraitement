#include "FrameOutil.h"

FrameOutil::FrameOutil(const wxString& title, const wxPoint& pos, const wxSize& size,MyApp* ap)
: wxFrame(NULL, wxID_ANY, title, pos, size),app(ap)
{

    wxImage* im = new wxImage(wxT("./rotate.jpg"));
    //wxBitmap bitmapp = wxBitmap(*im);
    //bouton1 = new wxBitmapButton(this,wxID_ANY,bitmapp);

    //delete bitmapp;
    //delete im;
}
