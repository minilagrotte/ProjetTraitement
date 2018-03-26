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
            if(sqrt(pow((float)x-(float)i,2)+pow((float)y-(float)j,2)) <= this->getSize()){
                img->SetPixel(data, width, height, i, j, r, g, b);
            }
        }
    }

    return nullptr;
}

MyImage* ToolCircle::drawLine(MyImage* img, int x1, int y1, int x2, int y2){
    float vx = sqrt(pow(x2-x1,2));
    float vy = sqrt(pow(y2-y1,2));
    for(int i = 0;i<=vx;i++){
        draw(img,i,y1+(vy/vx)*i);
    }
    return img;
}

