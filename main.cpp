#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"
#include <iostream>

using namespace sf;
using namespace std;


bool collisionDetection(Ball& b, Paddle& p)
{
    static int i = 0;
    bool result = false;
    result = b.getRectangle().intersects(p.getRectangle());
    cout << "b "  << b.getRectangle().left << "," << b.getRectangle().top << "," << b.getRectangle().width << "," << b.getRectangle().height <<  endl;
    cout << "p "  << p.getRectangle().left << "," << p.getRectangle().top << "," << p.getRectangle().width << "," << p.getRectangle().height <<  endl;
    if (result)
    {
        cout << "collision "  << ++i <<  endl;
        b.velocityYneg();
    }

    return result;
}

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML window");

    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60); // call it once, after creating the window

    Ball ball(window,50,50);
    Paddle paddle(window,100,window.getSize().y-100);
	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::MouseMoved)
            {
                paddle.update(window);
            }

            if (event.type == Event::MouseWheelMoved)
            {
                ball.velocityUp();
            }

            if (event.type == Event::KeyPressed)
            {
               cout << "code:" << event.key.code << endl;
            }
            // Close window : exit
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        collisionDetection(ball,paddle);

        ball.update();
        // Clear screen
        window.clear(sf::Color::White);
        // Draw the sprite
        window.draw(ball);

        window.draw(paddle);
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
