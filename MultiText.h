//
// Created by Alex on 3/20/2022.
//

#ifndef MAIN_CPP_MULTITEXT_H
#define MAIN_CPP_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Letter.h"
#include "SnapShot.h"
#include <list>


class MultiText : public sf::Drawable{
private:
    Letter letter;
    sf::Text blinkingLine;
    sf::Clock clock;

    float y = 0;
    float x = letter.getGlobalBounds().left + letter.getGlobalBounds().width;
    std::list<Letter> letters;
    sf::Font font;
    bool canType = false;

    int tracker = 0;
public:

    MultiText();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void begin();
    void end();


    std::string getText();
    bool checkCanType();
    void enableType();
    void disableType();
    void setPositionText(float x, float y);
    void setPositionBlinking(float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_MULTITEXT_H
