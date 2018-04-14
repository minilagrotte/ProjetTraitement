#ifndef CRAYON_H
#define CRAYON_H

#include <Forme.h>
#include <vector>


class Crayon : public Forme
{
    public:
        Crayon();
        virtual ~Crayon();
        void draw(wxPaintDC& ctx) override;


        void onLeftDown(wxPoint coord);
        void onLeftUP(wxPoint coord);
        void onMouseMov(wxPoint coord);
    protected:

    private:
        std::vector<wxPoint> points;
};

#endif // CRAYON_H
