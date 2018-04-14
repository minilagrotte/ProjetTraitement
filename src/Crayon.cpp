#include "Crayon.h"

Crayon::Crayon()
{
    points = std::vector<wxPoint>();
}

Crayon::~Crayon()
{
    //dtor
}

void Crayon::draw(wxPaintDC& ctx){
    ctx.SetPen(m_pen);
    for(int i = 0; i < points.size()-1;i++){
        ctx.DrawLine(points.at(i), points.at(i+1));
    }
}


void Crayon::onLeftDown(wxPoint coord){
    points.push_back(coord);
}
void Crayon::onLeftUP(wxPoint coord){
    finConstruction = true;
}
void Crayon::onMouseMov(wxPoint coord){
    points.push_back(coord);
}
