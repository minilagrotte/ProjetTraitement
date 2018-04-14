#ifndef TRAIT_H
#define TRAIT_H

#include <Forme.h>



class Trait : public Forme
{
    public:
        Trait(wxPoint point1, wxPoint point2);
        virtual ~Trait();
        void draw(wxPaintDC& ctx) override;

        void setP1(wxPoint p){p1 = p;}
        void setP2(wxPoint p){p2 = p;}

        wxPoint getP1(){return p1;}
        wxPoint getP2(){return p2;}

        void onLeftDown(wxPoint coord);
        void onLeftUP(wxPoint coord);
        void onMouseMov(wxPoint coord);

    protected:

    private:
        wxPoint p1;
        wxPoint p2;
};

#endif // TRAIT_H
