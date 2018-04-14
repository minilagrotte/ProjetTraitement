#ifndef FRAMECOLORPICKER_H
#define FRAMECOLORPICKER_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/clrpicker.h>
#include "MyApp.h"

class FrameColorPicker : public wxFrame
{
    public:
        FrameColorPicker(const wxString& title, const wxPoint& pos, const wxSize& size, MyApp* app_);
        virtual ~FrameColorPicker();
        wxColor getColor();
        wxColor getCurrentColor();

        wxColourPickerCtrl* colorPicker;
    protected:

    private:
        MyApp* app;
};

#endif // FRAMECOLORPICKER_H
