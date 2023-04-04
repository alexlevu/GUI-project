//
// Created by Alex on 4/17/2022.
//

#ifndef MAIN_CPP_FINALFILESMENU_H
#define MAIN_CPP_FINALFILESMENU_H
#include "SFML/Graphics.hpp"
#include "FileMenu.h"
#include <iostream>
#include "States.h"

class FinalFilesMenu : public sf::Drawable{
private:
    FileMenu menu1;
    FileMenu menu2;

    States states;

public:

    FinalFilesMenu();

    sf::FloatRect getGlobalBounds() const;
    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_FINALFILESMENU_H
