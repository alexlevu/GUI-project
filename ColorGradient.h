//
// Created by Alex on 5/6/2022.
//

#ifndef MAIN_CPP_COLORGRADIENT_H
#define MAIN_CPP_COLORGRADIENT_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include <iostream>

class ColorGradient : public sf::Drawable{
private:
    float x = 0;
    float y = 0;

    sf::VertexArray lines;
    States state;
public:

    ColorGradient();
    ColorGradient(std::string color, float x, float y);

    void enableHidden();
    void disableHidden();
    void getStateHidden();
    void setColor(std::string color);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //MAIN_CPP_COLORGRADIENT_H
