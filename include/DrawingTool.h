#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class DrawingTool
{
    public:
        DrawingTool(wxColor color = wxNullColour, int size = 0, wxString name = wxT("default name tool"));
        virtual ~DrawingTool();

        wxColor getColor();
        int getSize();
        wxString getName();

        void setColor(wxColor nColor);
        void setSize(int nSize);
        void setName(wxString nName);
    protected:

        wxColor m_color;
        int m_size;
        wxString m_name;

    private:
};

#endif // DRAWINGTOOL_H
