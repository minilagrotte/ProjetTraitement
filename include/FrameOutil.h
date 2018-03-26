#ifndef FRAMEOUTIL_H
#define FRAMEOUTIL_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp;

class FrameOutil: public wxFrame
{
public:
    FrameOutil(const wxString& title, const wxPoint& pos, const wxSize& size,MyApp* ap);
    void InitButton();
    void onPresse(wxCommandEvent &event);
private:
    MyApp* app;
    wxPanel* panel;

DECLARE_EVENT_TABLE()
};

#endif // FRAMEOUTIL_H
