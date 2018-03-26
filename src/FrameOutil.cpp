#include "FrameOutil.h"
#include "MyApp.h"
#include "enumeration.cpp"

FrameOutil::FrameOutil(const wxString& title, const wxPoint& pos, const wxSize& size,MyApp* ap)
: wxFrame(NULL, wxID_ANY, title, pos, size),app(ap)
{
    panel = new wxPanel(this);
}

void FrameOutil::InitButton(){
    ///Bouton pour la rotation
    wxImage *im = new wxImage(wxT("./rotate.jpg"));
    wxBitmap bitmapp = wxBitmap(*im);
    wxBitmapButton *bouton1 = new wxBitmapButton(panel,ID_Rotate,bitmapp);
}

void FrameOutil::onPresse(wxCommandEvent& event){
    app->action(event);
}


BEGIN_EVENT_TABLE(FrameOutil,wxFrame)
    EVT_BUTTON(ID_Rotate, FrameOutil::onPresse)
END_EVENT_TABLE()
