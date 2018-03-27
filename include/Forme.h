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

    protected:

        wxPen m_pen;

    private:
};

#endif // FORME_H
