#include "paddle.h"

using namespace std;
using namespace sf;

Paddle::Paddle(RenderWindow& parentWindow, int x,int y)
{
    //ctor
    //texture.loadFromFile("ball.png");

    shape.setSize(Vector2f(50.0,20.0));
    //shape.setTexture(&texture);

    shape.setOrigin(shape.getSize().x/2,shape.getSize().y/2);
    shape.setPosition(x,y);

    shape.setFillColor(Color::Blue);

    parentWindowSize = parentWindow.getSize();

}

Paddle::~Paddle()
{
    //dtor
}

void Paddle::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(shape,states);
}

bool Paddle::IsOnTop(void)
{

        return false;
}

bool Paddle::IsOnBottom(void)
{

        return false;
}

bool Paddle::IsOnLeft(void)
{

        return false;
}

bool Paddle::IsOnRight(void)
{

        return false;
}

FloatRect Paddle::getRectangle(void)
{
    FloatRect fr;
    fr.left = shape.getPosition().x - shape.getOrigin().x;
    fr.width = shape.getSize().x;
    fr.top = shape.getPosition().y - shape.getOrigin().y;
    fr.height = shape.getSize().y;
    return fr;
}

void Paddle::update(RenderWindow& window)
{
    shape.setPosition(Mouse::getPosition(window).x,shape.getPosition().y);
}
