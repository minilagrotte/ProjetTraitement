#ifndef MYAPP_H
#define MYAPP_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp: public wxApp
{
public:
	virtual bool OnInit();

	MyFrame *frame;
	FrameOutil* frameOutil;
};


#endif // MYAPP_H
