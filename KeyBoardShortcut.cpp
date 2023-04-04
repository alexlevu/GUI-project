//
// Created by Alex on 4/3/2022.
//

#include "KeyBoardShortcut.h"

bool KeyBoardShortcut::isUndo() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
