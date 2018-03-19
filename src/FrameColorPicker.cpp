#include "FrameColorPicker.h"

FrameColorPicker::FrameColorPicker(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
    colorPicker = new wxColourPickerCtrl(this,wxID_ANY);
}

FrameColorPicker::~FrameColorPicker()
{
    //dtor
}
