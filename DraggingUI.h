//
// Created by Alex on 4/25/2022.
//

#ifndef MAIN_CPP_DRAGGINGUI_H
#define MAIN_CPP_DRAGGINGUI_H
#include <SFML/Graphics.hpp>
#include "States.h"
class DraggingUI : public sf::Drawable{
private:
    sf::Text text;
    sf::Font font;
    sf::RectangleShape line;
    sf::RectangleShape dragPart;
    sf::Text valueText;

    float scaleValue;
    float scaler;

public:
    DraggingUI();
    DraggingUI(std::string title, float length);

    sf::FloatRect getGlobalBounds();
    void setScaler(float value);

    float getScaleValue();
    float getXPosDrag();
    void setPosition(float x, float y);
    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MAIN_CPP_DRAGGINGUI_H
