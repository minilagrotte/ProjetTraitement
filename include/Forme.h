#ifndef FORME_H
#define FORME_H

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class Forme
{
    public:
        Forme();
        virtual ~Forme();
        virtual void draw(wxPaintDC& ctx);

        void setPen(wxPen pen);
        wxPen getPen();

        bool finConstruction;

        virtual void onLeftDown(wxPoint coord){};
        virtual void onLeftUP(wxPoint coord){};
        virtual void onMouseMov(wxPoint coord){};

    protected:

        wxPen m_pen;
        int nbClick;

    private:
};

#endif // FORME_H
