#ifndef MYPANEL_H
#define MYPANEL_H

#include "MyImage.h"
class MyPanel: public wxPanel
{
public:
    MyPanel( wxWindow *parent );
    ~MyPanel() ;
    void OpenImage(wxString fileName);
    void OnPaint(wxPaintEvent &WXUNUSED(event));
    void OnSaveFile(wxString fileName);
    void OnMirror(int id);
    void OnBlur(int id);
    void OnRotate();
    void OnNegatif();
    void OnDesaturate();
    void OnSeuil();
    void OnMirrorMain(int id);
    void OnRotate90Main();
    void OnPosterize();
    void OnHistogramme();

    bool isImage();
private :
    MyImage *m_image = nullptr;		// used to load and process the image
    wxBitmap m_bitmap ;	// used to display the image
};


#endif // MYPANEL_H
