#ifndef FRAMECOLORPICKER_H
#define FRAMECOLORPICKER_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/clrpicker.h>

class FrameColorPicker : public wxFrame
{
    public:
        FrameColorPicker(const wxString& title, const wxPoint& pos, const wxSize& size);
        virtual ~FrameColorPicker();

        wxColourPickerCtrl* colorPicker;
    protected:

    private:
};

#endif // FRAMECOLORPICKER_H
