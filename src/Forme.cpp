#include "Forme.h"

Forme::Forme()
{

}

Forme::~Forme()
{

}

void Forme::draw(wxPaintDC& ctx)
{
}

void Forme::setPen(wxPen pen){
    m_pen = pen;
}
wxPen Forme::getPen(){
    return m_pen;
}
