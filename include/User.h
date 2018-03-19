#ifndef USER_H
#define USER_H


class User
{
    public:
        User();
        virtual ~User();

        inline int getSizeBrush(){return brushSize};
        inline wxColor getColor(){return color};

        void setSizeBrush(int _size){this->brushSize = _size};
        void setColor(wxColor _color){this->color = _color};

    protected:

    private:
        wxColor color;
        int brushSize;
};

#endif // USER_H
