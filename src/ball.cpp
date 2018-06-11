#include "ball.h"

using namespace std;
using namespace sf;

Ball::Ball(RenderWindow& parentWindow, int x,int y)
{
    //ctor
    texture.loadFromFile("ball.png");
    radius = (texture.getSize().x / 2.0)*0.5;

    shape.setRadius(radius);
    shape.setTexture(&texture);

    shape.setOrigin(radius,radius);
    shape.setPosition(Vector2f(x,y));

    parentWindowSize = parentWindow.getSize();

    velocity.x = 1;
    velocity.y = 1;

    spin = 1;
}

Ball::~Ball()
{
    //dtor
}

void Ball::velocityUp(void)
{
    velocity.x++;
    velocity.y++;
}

void Ball::velocityDown(void)
{
    velocity.x--;
    velocity.y--;
}

void Ball::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(shape,states);
}

bool Ball::IsOnTop(void)
{
    if (shape.getPosition().y - shape.getRadius() <= 0)
        return true;
    else
        return false;
}

bool Ball::IsOnBottom(void)
{
    if (shape.getPosition().y + shape.getRadius() >= parentWindowSize.y)
        return true;
    else
        return false;
}

bool Ball::IsOnLeft(void)
{
    if (shape.getPosition().x - shape.getRadius() <= 0)
        return true;
    else
        return false;
}

bool Ball::IsOnRight(void)
{
    if (shape.getPosition().x + shape.getRadius() >= parentWindowSize.x)
        return true;
    else
        return false;
}

FloatRect Ball::getRectangle(void)
{
    FloatRect fr;
    fr.left = shape.getPosition().x - shape.getOrigin().x;
    fr.width = 2.0 * shape.getRadius();
    fr.top = shape.getPosition().y - shape.getOrigin().y;
    fr.height = 2.0 * shape.getRadius();
    return fr;
}

void Ball::velocityXneg(void)
{
    velocity.x *= -1;
}

void Ball::velocityYneg(void)
{
    velocity.y *= -1;
}

void Ball::update(void)
{
    if (IsOnBottom() || IsOnTop())
    {
        velocity.y *= -1;
        spin *= -1;
    }

    if (IsOnLeft() || IsOnRight())
    {
        velocity.x*= -1;
        //spin *= -1;
    }

    shape.rotate(spin);

    shape.move(velocity);
}
