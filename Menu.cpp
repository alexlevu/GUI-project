//
// Created by Alex on 4/10/2022.
//

#include "Menu.h"

Menu::Menu() {
    menuList.push_back(drop1);
    menuList.push_back(drop2);
    menuList.push_back(drop3);

    for (int i = 0; i < menuList.size(); i++)
    {
        menuList[i].setPosition(posX, posY);
        posX += menuList[i].getGlobalBounds().width;
    }
}

Menu::Menu(float x, float y) {
    posX = x;
    posY = y;


    drop1.disableMenu();
    drop1.setTitle("File");
    drop1.push(menuOptions1);
    drop1.push(menuOptions2);

    drop2.disableMenu();
    drop2.setTitle("Edit");

    drop3.disableMenu();
    drop3.setTitle("Render");

    menuList.push_back(drop1);
    menuList.push_back(drop2);
    menuList.push_back(drop3);

    for (int i = 0; i < menuList.size(); i++)
    {
        menuList[i].setPosition(posX, posY);
        posX += menuList[i].getGlobalBounds().width;
    }
}

void Menu::update() {
    for (int i = 0; i < menuList.size(); i++)
    {
        menuList[i].update();
    }
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    for (int i = 0; i < menuList.size(); i++)
    {
        menuList[i].addEventHandler(window, event);
    }


}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < menuList.size(); i++)
    {
        window.draw(menuList[i]);
    }
}

void Menu::setPosition(float x, float y) {
    posX = x;
    posY = y;

    for (int i = 0; i < menuList.size(); i++)
    {
        menuList[i].setPosition(posX, posY);
        posX += menuList[i].getGlobalBounds().width;
    }
}

void Menu::push(DropDownMenu drop)
{
    drop.setPosition(posX, posY);
    menuList.push_back(drop);
    posX += drop.getGlobalBounds().width;
}

std::vector<DropDownMenu> Menu::getMenuList() {
    return menuList;
}


