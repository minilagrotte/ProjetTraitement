#include "DrawingTool.h"

DrawingTool::DrawingTool(wxColor color, int size, wxString name)
    : m_color(color),m_size(size),m_name(name)
{}

DrawingTool::~DrawingTool()
{

}

wxColour DrawingTool::getColor()
{
    return this->m_color;
}

int DrawingTool::getSize()
{
    return this->m_size;
}

wxString DrawingTool::getName()
{
    return this->m_name;
}

void DrawingTool::setColor(wxColour nColor)
{
    this->m_color = nColor;
}

void DrawingTool::setSize(int nSize)
{
    this->m_size = m_size;
}

void DrawingTool::setName(wxString nName)
{
    this->m_name = nName;
}
