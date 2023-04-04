//
// Created by Alex on 4/10/2022.
//

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H
#include <SFML/Graphics.hpp>
#include "DropDownMenu.h"

class Menu : public sf::Drawable{
private:
    std::vector<DropDownMenu> menuList;

    DropDownMenu drop1 = DropDownMenu("Close Project", "New Project", "Open Project", "File");
    MenuOptions menuOptions1 = MenuOptions("Quit");
    MenuOptions menuOptions2 = MenuOptions("Save Project");

    DropDownMenu drop2 = DropDownMenu("Redo", "Undo", "----", "Edit");

    DropDownMenu drop3 = DropDownMenu("Export Image", "----", "----", "Render");


    float posX = 100;
    float posY = 100;
public:
    Menu();
    Menu(float x, float y);

    void push(DropDownMenu drop);
    void setPosition(float x, float y);
    std::vector<DropDownMenu> getMenuList();

    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_MENU_H
