#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Ball : public Drawable
{
    public:
        Ball(RenderWindow& parentWindow, int x,int y);
        ~Ball();
        void update(void);
        void velocityUp(void);
        void velocityDown(void);
        void velocityXneg(void);
        void velocityYneg(void);
        FloatRect getRectangle();
    protected:

    private:
        Vector2u parentWindowSize;
        CircleShape shape;
        float radius;
        Texture texture;
        Vector2f velocity;
        int spin;
        void draw(RenderTarget& target, RenderStates states) const override;
        bool IsOnTop(void);
        bool IsOnBottom(void);
        bool IsOnLeft(void);
        bool IsOnRight(void);
};

#endif // BALL_H
