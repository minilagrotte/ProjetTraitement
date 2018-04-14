#ifndef MYAPP_H
#define MYAPP_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MyFrame.h"
#include "FrameOutil.h"
class FrameColorPicker ;

class MyApp: public wxApp
{
public:
	virtual bool OnInit();
	void action(wxCommandEvent& event);
	wxColor getCurrentColor();
private:
    MyFrame* frame;
    FrameOutil* frameOutil;
    FrameColorPicker* frameDessin;
};


#endif // MYAPP_H
