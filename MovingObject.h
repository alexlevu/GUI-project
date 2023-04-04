//
// Created by Alex on 2/7/2022.
//

#ifndef SFML_PROJECT_MOVINGOBJECT_H
#define SFML_PROJECT_MOVINGOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>

template <class T>
class MovingObject : public sf::Drawable, sf::Transformable {
private:
    T object;
    float x = 4, y = 4;
public:
    MovingObject<T>();

    void setRadius(int radius);

    void setSize(int x, int y);
    void setFillColor(sf::Color color);

    void setPosition(float x, float y);

    void bounce(sf::Vector2u windowSize);

    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#include "MovingObject.cpp"
#endif //SFML_PROJECT_MOVINGOBJECT_H
