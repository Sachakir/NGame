#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED

class Bloc
{
    public:
        Bloc(int x,int y,int width,int height);
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
    private:
        int x;
        int y;
        int width;
        int height;
};

#endif // BLOC_H_INCLUDED
