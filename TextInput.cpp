//
// Created by Alex on 3/22/2022.
//

#include "TextInput.h"

TextInput::TextInput()
{
    theTypingBox.setSize({400, 55});
    theTypingBox.setFillColor(sf::Color::Black);
    theTypingBox.setOutlineThickness(5);
    theTypingBox.setOutlineColor(sf::Color::White);
    theTypingBox.setPosition(posX, posY);

    font.loadFromFile("OpenSans-Bold.ttf");
    textLabel.setFont(font);

    textLabel.setCharacterSize(30);
    textLabel.setString("Enter Text");
    textLabel.setPosition(posX, posY - 55);
    textLabel.setFillColor(sf::Color::White);

    text.setPositionText(theTypingBox.getPosition().x, theTypingBox.getPosition().y);

}


void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    text.addEventHandler(window, event);


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if(theTypingBox.getGlobalBounds().contains(mousePos))
        {
            if(!boxState.isEnabled(CLICKED))
            {
                boxState.enableState(CLICKED);
                text.enableType();
            }



        }
        else
        {
            text.disableType();
            boxState.disableState(CLICKED);
        }
    }

}

void TextInput::update()
{
    if(boxState.isEnabled(CLICKED))
    {
        theTypingBox.setOutlineThickness(5);
        theTypingBox.setOutlineColor(sf::Color::White);
    }
    else
    {
        theTypingBox.setOutlineThickness(0);
        theTypingBox.setOutlineColor(sf::Color::Black);
    }
}


void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(theTypingBox);
    window.draw(text);
    window.draw(textLabel);
}

void TextInput::setPosition(float x, float y) {
    theTypingBox.setPosition(x, y);
    text.setPositionText(x, y);
    textLabel.setPosition(x, y - 50);
}

void TextInput::setLabel(std::string message)
{
    textLabel.setString(message);
}

sf::Vector2<float> TextInput::getPosition() {
    return theTypingBox.getPosition();
}

std::string TextInput::getText() {
    return text.getText();
}

