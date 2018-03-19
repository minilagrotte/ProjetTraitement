#include "User.h"

User::User()
{
    color = new wxColor(0,0,0);
    brushSize = 10;
}

User::~User()
{
}

int User::getSizeBrush(){return brushSize;}
wxColor* User::getColor(){return color;}

void User::setSizeBrush(int _size){this->brushSize = _size;}
void User::setColor(wxColor* _color){this->color = _color;}
