//
// Created by Alex on 2/12/2022.
//

#ifndef TEMPLATESFML_SHADOWBOX_H
#define TEMPLATESFML_SHADOWBOX_H
#include <SFML/Graphics.hpp>

class ShadowBox : public sf::Drawable, sf::Transformable{
private:
    sf::Font font;
    sf::Text textShadow;
    sf::Text text;
    sf::Color color = sf::Color::White;

    float scaler;
    float scaleValue;

public:
    ShadowBox();
    ShadowBox(std::string text);

    sf::Vector2<float> getPosition();
    void setTransparency(float x);
    float getTransparency();
    void setPosition(float x, float y);
    void setString(std::string text);
    void setSkew(float skew);
    void setFont(std::string file);
    float getSkew();
    void setCharacterSize(float size);
    void setColor(sf::Color color);
    void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //TEMPLATESFML_SHADOWBOX_H
