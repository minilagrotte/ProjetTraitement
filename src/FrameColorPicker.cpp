#include "FrameColorPicker.h"

FrameColorPicker::FrameColorPicker(const wxString& title, const wxPoint& pos, const wxSize& size, MyApp* app_)
: app(app_),wxFrame(NULL, wxID_ANY, title, pos, size)
{
    colorPicker = new wxColourPickerCtrl(this,wxID_ANY);
}

FrameColorPicker::~FrameColorPicker()
{
    //dtor
}
