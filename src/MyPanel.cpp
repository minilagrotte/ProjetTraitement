#include "MyPanel.h"
#include "enumeration.cpp"
#include "MyRotateDialog.h"
#include "MyThresholdDialog.h"
#include "Trait.h"
//////////////////Constructeur ///////////////////////////      //voir memoryDC pour calque
MyPanel::MyPanel(wxWindow *parent)
: wxPanel(parent) {
    Bind(wxEVT_PAINT, &MyPanel::OnPaint, this) ;
    actions = {};
	Bind(wxEVT_LEFT_DOWN, &MyPanel::OnMouseLeftDown,this);
	Bind(wxEVT_LEFT_UP, &MyPanel::OnMouseLeftUP,this);
	Bind(wxEVT_MOTION, &MyPanel::onMouseMov,this);
	mouseLeftDown = false;
	currentPen = wxPen(wxColor(200,200,200),5,wxPENSTYLE_SOLID);
}


MyPanel::~MyPanel() {
}

/////////////////////Methode de MyPanel//////////////////
void MyPanel::OpenImage(wxString path){
    if(m_image != nullptr){
        m_image->Destroy();
    }
    m_image = new MyImage(path);
    wxSize size = m_image->GetSize();
    this->GetParent()->SetClientSize(size);
    Refresh();
}

void MyPanel::OnPaint(wxPaintEvent &WXUNUSED(event)){
    if(m_image != nullptr){
        m_bitmap = wxBitmap(*m_image);
        wxPaintDC dc(this);
        dc.DrawBitmap(m_bitmap,0,0);
        drawAction(dc);
    }
}

void MyPanel::OnSaveFile(wxString fileName){
    m_bitmap.SaveFile(fileName,wxBITMAP_TYPE_JPEG);
    //wxLogMessage(wxT("Je suis sauvegarde"));

}

void MyPanel::OnMirror(int id){
    *m_image = m_image->Mirror(id == ID_Mirror_hor);
    Refresh();
}

void MyPanel::OnBlur(int id){
    //m_image->Mirror(true);
    if(id == ID_Blur){
        *m_image = m_image->Blur(1);
    } else if(id == ID_Anti_Blur){
        *m_image = m_image->Blur(-10);
    }
    Refresh();
}

void MyPanel::OnRotate(){
    MyRotateDialog* d = new MyRotateDialog(this); //(this, -1, wxT("Threshold"), wxDefaultPosition, wxSize(250,140));
    int ok = d->ShowModal();
    wxSize size;
    int res = d->RadioBox1->GetSelection();
    switch(res) {
        case 0:
            *m_image = m_image->Rotate90();
            size = m_image->GetSize();
            this->GetParent()->SetClientSize(size);
            break;
        case 1:
            *m_image = m_image->Rotate180();
            size = m_image->GetSize();
            this->GetParent()->SetClientSize(size);
            break;
        case 2:
            *m_image = m_image->Rotate90(false);
            size = m_image->GetSize();
            this->GetParent()->SetClientSize(size);
            break;
        default:
            wxString s;
            s.sprintf("%d",res);
            wxLogMessage(s);
    }
    Refresh();
}

void MyPanel::OnNegatif(){
    m_image->negative();
    Refresh();
}

void MyPanel::OnDesaturate(){
    m_image->Desaturate();
    Refresh();
}

void MyPanel::OnSeuil(){
    MyThresholdDialog *dlg = new MyThresholdDialog(this, -1, wxT("Threshold"), wxDefaultPosition, wxSize(250,140)) ;
    dlg->ShowModal();
    m_image->Threshold(dlg->m_threshold->GetValue());
    Refresh();
}

void MyPanel::OnMirrorMain(int id){
    m_image->Mirroir(id == ID_Mirror_ver_main);
    Refresh();
}

void MyPanel::OnRotate90Main(){
    MyImage* m = m_image;
    m_image = m_image->Rotation90();
    if(m != nullptr){
        m->Destroy();
    }
    this->GetParent()->SetClientSize(m_image->GetSize());
    Refresh();
}
void MyPanel::OnPosterize(){
    m_image->posterize();
    Refresh();
}

void MyPanel::OnHistogramme(){
    int nb = m_image->histogramme();
    wxString s;
    s.sprintf("il y a %d couleurs sur cette image",nb);
    wxLogMessage(s);
    Refresh();
}

bool MyPanel::isImage(){
    return m_image != nullptr;
}

void MyPanel::OnMouseLeftDown(wxMouseEvent& event){
    if(isImage()){
        Trait* t = new Trait(event.GetPosition(),event.GetPosition());
        t->setPen(currentPen);
        this->actions.push_back(t);
        Refresh();
    }
    mouseLeftDown = true;
}

void MyPanel::OnMouseLeftUP(wxMouseEvent& event){
    mouseLeftDown = false;
}

void MyPanel::onMouseMov(wxMouseEvent& event){
    if(isImage() && mouseLeftDown){
        Trait* t = (Trait*)actions.back();
        t->setP2(event.GetPosition());
        Refresh();
    }
}

void MyPanel::drawAction(wxPaintDC& dc){

    for(Forme* f : actions){
        f->draw(dc);
    }

}

void MyPanel::undoDraw(){
    if(!actions.empty())
        actions.pop_back();
    Refresh();
}
