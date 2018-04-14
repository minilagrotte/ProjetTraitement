#include "FrameColorPicker.h"
#include "enumeration.cpp"

FrameColorPicker::FrameColorPicker(const wxString& title, const wxPoint& pos, const wxSize& size, MyApp* app_)
: app(app_),wxFrame(NULL, wxID_ANY, title, pos, size)
{
    m_panel = new wxPanel(this);
    colorPicker = new wxColourPickerCtrl(m_panel,wxID_ANY,wxColor(0,0,0),wxDefaultPosition,wxSize(50,50));
    sizePicker = new wxSpinCtrl(m_panel,ID_SizeSelection,wxEmptyString,wxPoint(50,0),wxSize(50,20));
    sizePicker->SetRange(1,2500);
    sizePicker->SetValue(10);

    Refresh();
}

void FrameColorPicker::InitButton(){
    ///Trait
    wxImage *im = new wxImage(wxT("./trait.png"));
    wxBitmap* bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonTrait = new wxBitmapButton(m_panel,ID_Trait,*bitmapp,wxPoint(0,50),wxSize(50,50));
    delete im;
    delete bitmapp;
    ///Crayon
    im = new wxImage(wxT("./crayon.png"));
    bitmapp = new wxBitmap(*im);
    wxBitmapButton* boutonCrayon = new wxBitmapButton(m_panel,ID_Crayon,*bitmapp,wxPoint(0,100),wxSize(50,50));

}

FrameColorPicker::~FrameColorPicker()
{
    //dtor
}
wxColor FrameColorPicker::getCurrentColor()
{
    return this->colorPicker->GetColour();
}

void FrameColorPicker::onOutilSelected(wxCommandEvent& event){
    app->setOutilCourrant(event.GetId());
}

int FrameColorPicker::getCurrentSize(){
    return sizePicker->GetValue();
}

BEGIN_EVENT_TABLE(FrameColorPicker,wxFrame)
    EVT_BUTTON(ID_Trait, FrameColorPicker::onOutilSelected)
    EVT_BUTTON(ID_Crayon, FrameColorPicker::onOutilSelected)
END_EVENT_TABLE()
