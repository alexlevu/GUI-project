//
// Created by Alex on 3/22/2022.
//

#ifndef MAIN_CPP_TEXTINPUT_H
#define MAIN_CPP_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "MultiText.h"
#include "States.h"


class TextInput : public sf::Drawable{
private:
    MultiText text;
    float posX = 0;
    float posY = 100;
    sf::RectangleShape theTypingBox;


    sf::Font font;
    sf::Text textLabel;
    States boxState;

public:
    TextInput();

    std::string getText();
    void setPosition(float x, float y);
    sf::Vector2<float> getPosition();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setLabel(std::string message);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_TEXTINPUT_H
