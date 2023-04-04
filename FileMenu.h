//
// Created by Alex on 4/17/2022.
//

#ifndef MAIN_CPP_FILEMENU_H
#define MAIN_CPP_FILEMENU_H
#include "FileItem.h"
#include "SFML/Graphics.hpp"
#include "SnapShot.h"
#include <string>

class FileMenu : public sf::Drawable{
private:
    sf::RectangleShape menu;
    std::vector<FileItem> options;
    States FileMenuState;
    sf::Sprite menuIcon;

    sf::Text title;
    sf::Font font;

    SnapShot<std::string> snapShot;

    FileItem item1 = FileItem(FILEPIC, "ALEX");
    FileItem item2 = FileItem(FILEPIC, "Allen");
    FileItem item3 = FileItem(FILEPIC, "Alvin");

    float initialX;
    float initialY;
public:
    FileMenu();
    FileMenu(std::string menuTitle, float x, float y);

    void setPosition(float x, float y);
    void setSize(float x, float y);
    void push(FileItem item);
    sf::FloatRect getGlobalBounds() const;
    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_FILEMENU_H
