#ifndef FRAMECOLORPICKER_H
#define FRAMECOLORPICKER_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/clrpicker.h>
#include <wx/spinctrl.h>
#include "MyApp.h"

class FrameColorPicker : public wxFrame
{
    public:
        FrameColorPicker(const wxString& title, const wxPoint& pos, const wxSize& size, MyApp* app_);
        virtual ~FrameColorPicker();
        //wxColor getColor();
        wxColor getCurrentColor();
        int getCurrentSize();
        void InitButton();
        void onOutilSelected(wxCommandEvent& event);

        wxColourPickerCtrl* colorPicker;
        wxSpinCtrl* sizePicker;
        wxPanel* m_panel;
    protected:

    private:
        MyApp* app;

DECLARE_EVENT_TABLE()
};

#endif // FRAMECOLORPICKER_H
