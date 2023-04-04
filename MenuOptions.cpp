//
// Created by Alex on 4/2/2022.
//

#include "MenuOptions.h"

MenuOptions::MenuOptions()
{
    box.setSize(sf::Vector2f(150, 30));
    box.setOutlineColor(sf::Color::Blue);
    box.setOutlineThickness(0);
    box.setFillColor(sf::Color::Black);

    font.loadFromFile("OpenSans-Bold.ttf");
    title.setFont(font);
    title.setString("Default");
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);

    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = box.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
}

MenuOptions::MenuOptions(std::string text)
{
    box.setSize(sf::Vector2f(150, 30));
    box.setOutlineColor(sf::Color::Blue);
    box.setOutlineThickness(0);
    box.setFillColor(sf::Color(128, 128, 128));

    font.loadFromFile("OpenSans-Bold.ttf");
    title.setFont(font);
    title.setString(text);
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);

    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = box.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
}

void MenuOptions::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(box.getGlobalBounds().contains(mousePos))
    {
        boxState.enableState(HOVERED);
    }
    else
    {
        boxState.disableState(HOVERED);
    }

}

void MenuOptions::update()
{
    if(boxState.isEnabled(HOVERED))
    {
        box.setFillColor(sf::Color::Blue);
        box.setOutlineThickness(5);
    }
    else if(!boxState.isEnabled(HOVERED))
    {
        box.setFillColor(sf::Color(128, 128, 128));
        box.setOutlineThickness(0);
    }

}


void MenuOptions::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    //states.transform = box.getTransform();
    window.draw(box);
    window.draw(title);
}

void MenuOptions::setPosition(float x, float y)
{
    box.setPosition(x, y);
    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = box.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
}

std::string MenuOptions::getTitle() {
    return title.getString();
}

sf::FloatRect MenuOptions::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void MenuOptions::setSize(float x, float y)
{
    box.setSize(sf::Vector2f(x, y));
    title.setCharacterSize(y - 10);

}

void MenuOptions::setText(std::string text) {
    title.setString(text);
}

sf::RectangleShape MenuOptions::getBox() const{
    return box;
}

