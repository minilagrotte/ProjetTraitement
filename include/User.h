#ifndef USER_H
#define USER_H
#include <wx/colour.h>

class User
{
    public:
        User();
        virtual ~User();

        inline int getSizeBrush();
        inline wxColor* getColor();

        void setSizeBrush(int _size);
        void setColor(wxColor* _color);

    protected:

    private:
        wxColor* color;
        int brushSize;
};

#endif // USER_H
