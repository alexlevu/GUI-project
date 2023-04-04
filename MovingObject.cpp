//
// Created by Alex on 2/7/2022.
//

#ifndef SFML_PROJECT_MOVINGOBJECT_CPP
#define SFML_PROJECT_MOVINGOBJECT_CPP

#include "MovingObject.h"

template<class T>
MovingObject<T>::MovingObject() {

}

template<class T>
void MovingObject<T>::setRadius(int radius)
{
    object.setRadius(radius);
}

template<class T>
void MovingObject<T>::setSize(int x, int y)
{
    object.setRadius(x, y);
}

template<class T>
void MovingObject<T>::setFillColor(sf::Color color)
{
    object.setFillColor(color);
}

template<class T>
void MovingObject<T>::setPosition(float x, float y)
{
    object.setPosition(x, y);
}


template<class T>
void MovingObject<T>::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(object);
}

template<class T>
void MovingObject<T>::bounce(sf::Vector2u windowSize)
{
    sf::Vector2f pos = object.getPosition();
    sf::FloatRect bounds = object.getGlobalBounds();

    if(pos.x <= 0)
    {
        x = 5;
    }
    else if(pos.x + bounds.width >= windowSize.x)
    {
        x = -7;
    }
    if(pos.y <= 0)
    {
        y = 3;
    }
    else if(pos.y + bounds.height >= windowSize.y)
    {
        y = -10;
    }

    object.move(x,y);

}

template<class T>
sf::FloatRect MovingObject<T>::getGlobalBounds()
{
    return object.getGlobalBounds();
}

#endif //SFML_PROJECT_MOVINGOBJECT_CPP