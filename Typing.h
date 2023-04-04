//
// Created by Alex on 2/26/2022.
//

#ifndef MAIN_CPP_TYPING_H
#define MAIN_CPP_TYPING_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextInput.h"
#include "SnapShot.h"

class Typing : public sf::Drawable{
private:
    TextInput text;
    SnapShot<TextInput> snap;
    sf::Clock clock;

public:
    Typing();

    void setPosition(float x, float y);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_TYPING_H
