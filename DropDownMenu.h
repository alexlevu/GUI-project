//
// Created by Alex on 4/2/2022.
//

#ifndef MAIN_CPP_DROPDOWNMENU_H
#define MAIN_CPP_DROPDOWNMENU_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MenuOptions.h"
#include <iostream>
#include <stack>
#include "SnapShot.h"
#include "KeyBoardShortcut.h"
#include "FileItem.h"
class DropDownMenu : public sf::Drawable{
private:
    sf::RectangleShape menu;
    std::vector<MenuOptions> options;
    States menuState;
    sf::Text title;
    sf::Font font;
    sf::Text text;
    bool disable = false;

    SnapShot<std::string> snapShot;

    MenuOptions item1;
    MenuOptions item2;
    MenuOptions item3;

    float initialX;
    float initialY;

public:
    DropDownMenu();
    DropDownMenu(std::string name, std::string name2, std::string name3, std::string text);
    DropDownMenu(float x, float y,std::string name, std::string name2, std::string name3);

    States getStates();
    void disableMenu();
    void setTitle(std::string text);
    std::vector<MenuOptions> getOptions();
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void push(MenuOptions item);
    sf::FloatRect getGlobalBounds() const;
    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //MAIN_CPP_DROPDOWNMENU_H
