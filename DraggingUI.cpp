//
// Created by Alex on 4/25/2022.
//

#include "DraggingUI.h"
DraggingUI::DraggingUI() {
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString("Default: ");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    text.setPosition(100, 100);

    line.setFillColor(sf::Color::White);
    line.setSize(sf::Vector2f(300, 2));
    line.setPosition(text.getPosition().x + text.getGlobalBounds().width, text.getGlobalBounds().top + text.getGlobalBounds().height/2 - line.getGlobalBounds().height/2);

    dragPart.setFillColor(sf::Color(162, 162, 162));
    dragPart.setSize(sf::Vector2f(15, 20));
    dragPart.setPosition(line.getPosition().x + line.getGlobalBounds().width, line.getGlobalBounds().top + line.getGlobalBounds().height/2 - dragPart.getGlobalBounds().height/2);

}

DraggingUI::DraggingUI(std::string title, float length) {
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString(title + ": ");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    text.setPosition(100, 100);

    valueText.setFont(font);
    valueText.setString(std::to_string(scaleValue));
    valueText.setFillColor(sf::Color::White);
    valueText.setCharacterSize(15);

    line.setFillColor(sf::Color::White);
    line.setSize(sf::Vector2f(length, 2));
    line.setPosition(text.getPosition().x + text.getGlobalBounds().width, text.getGlobalBounds().top + text.getGlobalBounds().height/2 - line.getGlobalBounds().height/2);

    valueText.setPosition(line.getPosition().x + line.getGlobalBounds().width, line.getGlobalBounds().top + line.getGlobalBounds().height/2 - valueText.getGlobalBounds().height/2);

    dragPart.setFillColor(sf::Color(162, 162, 162));
    dragPart.setSize(sf::Vector2f(15, 20));
    dragPart.setPosition(line.getPosition().x + line.getGlobalBounds().width/2 - dragPart.getGlobalBounds().width/2, line.getGlobalBounds().top + line.getGlobalBounds().height/2 - dragPart.getGlobalBounds().height/2);
}

void DraggingUI::update() {
    valueText.setString(std::to_string(scaleValue));
}

void DraggingUI::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if(dragPart.getGlobalBounds().contains(mousePos))
        {
            if (mousePos.x < line.getPosition().x || mousePos.x > line.getGlobalBounds().left + line.getGlobalBounds().width)
            {
                dragPart.setPosition(dragPart.getPosition().x, dragPart.getPosition().y);
            }
            else
            {
                dragPart.setPosition(mousePos.x - 6.5, dragPart.getPosition().y);
                scaleValue = dragPart.getPosition().x * scaler;
            }
        }
    }

}

void DraggingUI::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
    window.draw(line);
    window.draw(valueText);
    window.draw(dragPart);
}

void DraggingUI::setPosition(float x, float y) {
    text.setPosition(x, y);
    line.setPosition(x + text.getGlobalBounds().width, text.getGlobalBounds().top + text.getGlobalBounds().height/2 - line.getGlobalBounds().height/2);
    valueText.setPosition(line.getPosition().x + line.getGlobalBounds().width + 2, line.getGlobalBounds().top + line.getGlobalBounds().height/2 - valueText.getGlobalBounds().height/2 - 5);
    dragPart.setPosition(line.getPosition().x + line.getGlobalBounds().width/2 - dragPart.getGlobalBounds().width/2, line.getGlobalBounds().top + line.getGlobalBounds().height/2 - dragPart.getGlobalBounds().height/2);
}

sf::FloatRect DraggingUI::getGlobalBounds() {
    return dragPart.getGlobalBounds();
}

float DraggingUI::getXPosDrag() {
    return dragPart.getPosition().x;
}

float DraggingUI::getScaleValue() {
    return scaleValue;
}

void DraggingUI::setScaler(float value) {
    scaler = value/dragPart.getPosition().x;
    scaleValue = dragPart.getPosition().x * scaler;
}

