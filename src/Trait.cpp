#include "Trait.h"

Trait::Trait(wxPoint point1, wxPoint point2)
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
