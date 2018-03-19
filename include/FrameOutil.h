#ifndef FRAMEOUTIL_H
#define FRAMEOUTIL_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MyApp.h"

class FrameOutil: public wxFrame
{
public:
    FrameOutil(const wxString& title, const wxPoint& pos, const wxSize& size,MyApp* ap);
private:
    MyApp* app;
    wxButton* bouton1;
};

#endif // FRAMEOUTIL_H
