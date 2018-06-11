#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Paddle : public Drawable
{
public:
     Paddle(RenderWindow& parentWindow, int x,int y);
     ~Paddle();
     void update(RenderWindow& window);
     FloatRect getRectangle();
protected:

private:
     Vector2u parentWindowSize;
     RectangleShape shape;
     float width;
     float height;
     Texture texture;

     void draw(RenderTarget& target, RenderStates states) const override;
     bool IsOnTop(void);
     bool IsOnBottom(void);
     bool IsOnLeft(void);
     bool IsOnRight(void);
};

#endif // PADDLE_H
