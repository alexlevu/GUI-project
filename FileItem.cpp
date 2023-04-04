//
// Created by Alex on 4/17/2022.
//

#include "FileItem.h"
FileItem::FileItem() {

}

FileItem::FileItem(ImageName icon, std::string text) {
    this->icon.setTexture(Images::getImage(icon));
    setText(text);
    this->icon.setScale(0.05, 0.05);
    sf::FloatRect tb = this->icon.getGlobalBounds();

    this->icon.setPosition(getGlobalBounds().left, getGlobalBounds().top + getGlobalBounds().height/2 - tb.height/2);
}


sf::FloatRect FileItem::getGlobalBounds() const {
    return MenuOptions::getGlobalBounds();
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    MenuOptions::addEventHandler(window, event);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    sf::RectangleShape box = getBox();
    states.transform = box.getTransform();
    MenuOptions::draw(window, states);
    window.draw(icon, states);
}

void FileItem::update() {
    MenuOptions::update();
}


