#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    public:
        void setX(int x);
        int getX() const;
        void setY(int y);
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        int getXSpeed() const;
        int getYSpeed() const;
        void setXSpeed(int xSpeed);
        void setYSpeed(int ySpeed);
        Player();
    private:
        int x;
        int y;
        int xSpeed;
        int ySpeed;
        int width;
        int height;
};

#endif // PLAYER_H_INCLUDED