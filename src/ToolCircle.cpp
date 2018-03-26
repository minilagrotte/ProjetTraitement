#include "ToolCircle.h"

ToolCircle::ToolCircle(wxColor color, int size, wxString name)
    :DrawingTool(color,size,name)
{
}

ToolCircle::~ToolCircle()
{
}

MyImage* ToolCircle::draw(MyImage* img, int x, int y){
    unsigned char * data = img->GetData();
    int width = img->GetWidth();
    int height = img->GetHeight();

    unsigned char r = this->getColor().Red();
    unsigned char g = this->getColor().Green();
    unsigned char b = this->getColor().Blue();

    int idep = (x - this->getSize() > 0)?x - this->getSize():0;
    int ifin = (x + this->getSize() < width)?x + this->getSize():width;
    int jdep = (y - this->getSize()>0)?y - this->getSize():0;
    int jfin = (y + this->getSize() < height)?y + this->getSize():height;

    for(int i =idep; i < ifin; i++){
        for(int j =jdep; j < jfin; j++){
            if(sqrt(pow(x-i,2)+pow(y-j,2)) <= this->getSize()){
                img->SetPixel(data, width, height, i, j, r, g, b);
            }
        }
    }

    return nullptr;
}
