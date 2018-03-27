#ifndef TOOLCIRCLE_H
#define TOOLCIRCLE_H

#include <DrawingTool.h>
#include "MyImage.h"


class ToolCircle : public DrawingTool
{
    public:
        ToolCircle(wxColor color = wxNullColour, int size = 0, wxString name = wxT("default name tool"));
        virtual ~ToolCircle();

        MyImage* draw(MyImage* img, int x, int y);
        MyImage* drawLine(MyImage* img, int x1, int y1, int x2, int y2);

    protected:

    private:
};

#endif // TOOLCIRCLE_H
