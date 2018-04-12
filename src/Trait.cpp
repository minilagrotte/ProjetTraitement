#include "Trait.h"

Trait::Trait(wxPoint point1, wxPoint point2)
    :Forme()
{
    this->p1 = point1;
    this->p2 = point2;
    this->m_pen = wxPen(wxColor(0,0,0),10,wxPENSTYLE_SOLID);
}

Trait::~Trait()
{
    //dtor
}


void Trait::draw(wxPaintDC& ctx){
    ctx.SetPen(m_pen);
    ctx.DrawLine(p1,p2);
}

void Trait::onLeftDown(wxPoint coord){
    if(nbClick >= 2){
        finConstruction = true;
    }
    nbClick++;
}

void Trait::onLeftUP(wxPoint coord){
}

void Trait::onMouseMov(wxPoint coord){
    if(nbClick == 1){
        p1 = coord;
        p2 = coord;
    } else if (nbClick == 2){
        p2 = coord;
    }
}
