//
// Created by Alex on 2/26/2022.
//

#include "Typing.h"


Typing::Typing()
{
    text.setPosition(10, 10);
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if (clock.getElapsedTime().asSeconds() > 1)
    {
        snap.getSnapshot(text);
        clock.restart();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Z)
            {
                if (!snap.listIsEmpty())
                {
                    text = snap.getData1();
                }
            }
        }
    }



    text.eventHandler(window, event);

}

void Typing::update()
{
    text.update();
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
}

void Typing::setPosition(float x, float y)
{
    text.setPosition(x, y);
}

