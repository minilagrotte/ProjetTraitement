#ifndef FRAMEOUTIL_H
#define FRAMEOUTIL_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class FrameOutil: public wxFrame
{
public:
    FrameOutil(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
};

#endif // FRAMEOUTIL_H
