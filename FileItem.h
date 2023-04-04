//
// Created by Alex on 4/17/2022.
//

#ifndef MAIN_CPP_FILEITEM_H
#define MAIN_CPP_FILEITEM_H
#include "MenuOptions.h"
#include "Images.h"
#include "ImageName.h"

class FileItem : public MenuOptions{
private:
    sf::Sprite icon;

public:
    FileItem();
    FileItem(ImageName icon, std::string text);


    sf::FloatRect getGlobalBounds() const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //MAIN_CPP_FILEITEM_H
