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
};


#endif // MYAPP_H
