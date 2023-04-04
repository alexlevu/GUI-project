//
// Created by Alex on 2/12/2022.
//

#include "ShadowBox.h"
//set the shadow y + 160 of the text and x is same
ShadowBox::ShadowBox()
{
    color.a = 50;
    font.loadFromFile("OpenSans-Bold.ttf");
    textShadow.setFont(font);
    textShadow.setString("Alex Vu");
    textShadow.setCharacterSize(50);
    textShadow.setPosition(440,410);
    textShadow.setFillColor(color);
    textShadow.setScale(1, -0.5);
//
//    text.setFont(font);
//    text.setString("Alex Vu");
//    text.setCharacterSize(100);
//    text.setPosition(440, 250);
//    text.setFillColor(sf::Color::White);

}
ShadowBox::ShadowBox(std::string text)
{
    color.a = 50;
    font.loadFromFile("OpenSans-Bold.ttf");
    textShadow.setFont(font);
    textShadow.setString(text);
    textShadow.setCharacterSize(100);
    textShadow.setPosition(440,410);
    textShadow.setFillColor(color);
    textShadow.setScale(1, -0.5);
}



void ShadowBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    //window.draw(text);
    window.draw(textShadow);
}


void ShadowBox::setPosition(float x, float y) {
    //text.setPosition(x, y);
    textShadow.setPosition(x, y);
}

void ShadowBox::setString(std::string text) {
    //this->text.setString(text);
    textShadow.setString(text);
}

sf::Vector2<float> ShadowBox::getPosition() {
    return textShadow.getPosition();
}

void ShadowBox::setTransparency(float x) {
    color.a = x;
}

float ShadowBox::getTransparency() {
    return color.a;
}

void ShadowBox::update() {
    textShadow.setFillColor(color);
}

void ShadowBox::setColor(sf::Color color) {
    this->color = color;
    this->color.a = 50;
}

void ShadowBox::setCharacterSize(float size) {
    textShadow.setCharacterSize(size);
}

void ShadowBox::setSkew(float skew) {
    textShadow.setScale(textShadow.getScale().x, skew);
}

float ShadowBox::getSkew() {
    return textShadow.getScale().y;
}

void ShadowBox::setFont(std::string file) {
    font.loadFromFile(file);
    textShadow.setFont(font);
}



