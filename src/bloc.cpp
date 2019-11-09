#include "bloc.hpp"

Bloc::Bloc(int x,int y,int width,int height)
{
    Bloc::x = x;
    Bloc::y = y;
    Bloc::width = width;
    Bloc::height = height;
}

int Bloc::getX() const
{
    return Bloc::x;
}

int Bloc::getY() const
{
    return Bloc::y;
}

int Bloc::getWidth() const
{
    return Bloc::width;
}

int Bloc::getHeight() const
{
    return Bloc::height;
}