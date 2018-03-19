#ifndef MYFRAME_H
#define MYFRAME_H

#include "MyPanel.h"


class MyFrame: public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnSuperbe(wxCommandEvent& event);
	void OnResize(wxCommandEvent& event);
    void OnMouse(wxMouseEvent& event);
    void OnOpenImage(wxCommandEvent& event);
    void OnOpenImageDefault(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnProcess(wxCommandEvent& event);

    MyPanel* m_panel;
    clock_t t;
};

#endif // MYFRAME_H
