//
// Created by Alex on 4/17/2022.
//

#include "FinalFilesMenu.h"

FinalFilesMenu::FinalFilesMenu() {
    menu1 = FileMenu("Directory 1", 100, 100);
    menu2 = FileMenu("Directory 2", menu1.getGlobalBounds().left, menu1.getGlobalBounds().top);
}

sf::FloatRect FinalFilesMenu::getGlobalBounds() const {
    return sf::FloatRect();
}

void FinalFilesMenu::update() {

}

void FinalFilesMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void FinalFilesMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(menu1);
    window.draw(menu2);
}
