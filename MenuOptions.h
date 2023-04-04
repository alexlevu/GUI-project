//
// Created by Alex on 4/2/2022.
//

#ifndef MAIN_CPP_MENUOPTIONS_H
#define MAIN_CPP_MENUOPTIONS_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "States.h"

class MenuOptions : public sf::Drawable{
private:
    sf::RectangleShape box;
    sf::Text title;
    sf::Font font;
    States boxState;

public:
    MenuOptions();
    MenuOptions(std::string text);

    void setPosition(float x, float y);

    std::string getTitle();
    void update();

    sf::RectangleShape getBox() const;
    void setText(std::string text);
    void setSize(float x, float y);
    sf::FloatRect getGlobalBounds() const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_MENUOPTIONS_H
