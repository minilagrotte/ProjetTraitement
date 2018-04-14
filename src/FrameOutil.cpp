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
    wxBitmap* bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonRotation = new wxBitmapButton(panel,ID_Rotate,*bitmapp);
    delete im;
    delete bitmapp;
    ///Bouton pour les Mirrors
        //Horizontal
    im = new wxImage(wxT("./MirrorH.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonMirrorH = new wxBitmapButton(panel,ID_Mirror_hor,*bitmapp);
    boutonMirrorH->SetPosition(wxPoint(boutonRotation->GetSize().GetWidth(),0));
    delete im;
    delete bitmapp;
        //Vertical
    im = new wxImage(wxT("./MirrorV.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonMirrorV = new wxBitmapButton(panel,ID_Mirror_ver,*bitmapp);
    boutonMirrorV->SetPosition(wxPoint(boutonRotation->GetSize().GetWidth()*2,0));
    delete im;
    delete bitmapp;

    //Blur
    im = new wxImage(wxT("./Blur.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonBlur = new wxBitmapButton(panel,ID_Blur,*bitmapp);
    boutonBlur->SetPosition(wxPoint(boutonRotation->GetSize().GetWidth()*3,0));
    delete im;
    delete bitmapp;
    //AntiBlur
    im = new wxImage(wxT("./AntiBlur.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonAntiBlur = new wxBitmapButton(panel,ID_Anti_Blur,*bitmapp);
    boutonAntiBlur->SetPosition(wxPoint(boutonRotation->GetSize().GetWidth()*4,0));
    delete im;
    delete bitmapp;
    //Negative
    im = new wxImage(wxT("./Negative.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonNegative = new wxBitmapButton(panel,ID_Negatif,*bitmapp);
    boutonNegative->SetPosition(wxPoint(0,boutonRotation->GetSize().GetHeight()));
    delete im;
    delete bitmapp;
    //Desaturate
    im = new wxImage(wxT("./Desaturate.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonDesaturate = new wxBitmapButton(panel,ID_Desaturate,*bitmapp);
    boutonDesaturate->SetPosition(wxPoint(boutonRotation->GetSize().GetWidth(),boutonRotation->GetSize().GetHeight()));
    delete im;
    delete bitmapp;
    //Seuil
    im = new wxImage(wxT("./Seuil.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonSeuil = new wxBitmapButton(panel,ID_Seuil,*bitmapp);
    boutonSeuil->SetPosition(wxPoint(boutonRotation->GetSize().GetWidth()*2,boutonRotation->GetSize().GetHeight()));
    delete im;
    delete bitmapp;
    im = new wxImage(wxT("./Trame.jpg"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonTrame = new wxBitmapButton(panel,ID_TRAMAGE,*bitmapp);
    boutonTrame->SetPosition(wxPoint(boutonRotation->GetSize().GetWidth()*3,boutonRotation->GetSize().GetHeight()));
    delete im;
    delete bitmapp;
}

void FrameOutil::onPresse(wxCommandEvent& event){
    app->action(event);
}


BEGIN_EVENT_TABLE(FrameOutil,wxFrame)
    EVT_BUTTON(ID_Rotate, FrameOutil::onPresse)
    EVT_BUTTON(ID_Mirror_hor, FrameOutil::onPresse)
    EVT_BUTTON(ID_Mirror_ver,FrameOutil::onPresse)
    EVT_BUTTON(ID_Blur,FrameOutil::onPresse)
    EVT_BUTTON(ID_Anti_Blur,FrameOutil::onPresse)
    EVT_BUTTON(ID_Negatif,FrameOutil::onPresse)
    EVT_BUTTON(ID_Desaturate,FrameOutil::onPresse)
    EVT_BUTTON(ID_Seuil,FrameOutil::onPresse)
    EVT_BUTTON(ID_TRAMAGE,FrameOutil::onPresse)
END_EVENT_TABLE()
