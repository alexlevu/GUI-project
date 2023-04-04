//
// Created by Alex on 5/6/2022.
//

#include "ColorGradient.h"

ColorGradient::ColorGradient() {
    lines.setPrimitiveType(sf::LineStrip);
    lines.resize(255);

    for (int i = 0; i < lines.getVertexCount(); i++)
    {
        if(i % 2 == 0)
        {
            lines[i].position = sf::Vector2f(x, y);
            lines[i].color = sf::Color::Black;
            y = 255;
        }
        else
        {
            lines[i].position = sf::Vector2f(x, y);
            lines[i].color = sf::Color(i, i, 255);
            y = 0;
        }
        x++;
    }
}

ColorGradient::ColorGradient(std::string color, float x, float y) {
    lines.setPrimitiveType(sf::LineStrip);
    lines.resize(255);
    float tempX = x;
    float tempY = y;

    if(color == "Blue")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color::Black;
                y += 255;
            }
            else
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color(i, i, 255);
                y = tempY;
            }
            x++;
        }
    }
    else if (color == "Red")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color::Black;
                y += 255;
            }
            else
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color(255, i, i);
                y = tempY;
            }
            x++;
        }
    }
    else if(color == "Yellow")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color::Black;
                y += 255;
            }
            else
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color(255, 255, i);
                y = tempY;
            }
            x++;
        }
    }
    else if(color == "Green")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color::Black;
                y += 255;
            }
            else
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color(i, 255, i);
                y = tempY;
            }
            x++;
        }
    }

    else if(color == "Gray")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color::Black;
                y += 255;
            }
            else
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color(i, i, i);
                y = tempY;
            }
            x++;
        }
    }
    else if(color == "Cyan")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color::Black;
                y += 255;
            }
            else
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color(255-i, 255, 255);
                y = tempY;
            }
            x++;
        }
    }

    else if(color == "Magenta")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color::Black;
                y += 255;
            }
            else
            {
                lines[i].position = sf::Vector2f(x, y);
                lines[i].color = sf::Color(255, 255 - i, 255);
                y = tempY;
            }
            x++;
        }
    }

}

void ColorGradient::setColor(std::string color)
{
    if(color == "Blue")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].color = sf::Color::Black;
            }
            else
            {
                lines[i].color = sf::Color(i, i, 255);
            }
        }
    }
    else if (color == "Red")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].color = sf::Color::Black;
            }
            else
            {
                lines[i].color = sf::Color(255, i, i);
            }
        }
    }
    else if(color == "Yellow")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].color = sf::Color::Black;
            }
            else
            {
                lines[i].color = sf::Color(255, 255, i);
            }
        }
    }
    else if(color == "Green")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].color = sf::Color::Black;
            }
            else
            {
                lines[i].color = sf::Color(i, 255, i);
            }
        }
    }

    else if(color == "Gray")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].color = sf::Color::Black;
            }
            else
            {
                lines[i].color = sf::Color(i, i, i);
            }
        }
    }
    else if(color == "Cyan")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].color = sf::Color::Black;
            }
            else
            {
                lines[i].color = sf::Color(255-i, 255, 255);
            }
        }
    }

    else if(color == "Magenta")
    {
        for (int i = 0; i < lines.getVertexCount(); i++)
        {
            if(i % 2 == 0)
            {
                lines[i].color = sf::Color::Black;
            }
            else
            {
                lines[i].color = sf::Color(255, 255 - i, 255);
            }
        }
    }
}

void ColorGradient::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void ColorGradient::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(lines);
}

void ColorGradient::update() {

}

void ColorGradient::enableHidden() {
    state.enableState(HIDDEN);
}

void ColorGradient::disableHidden() {
    state.disableState(HIDDEN);
}

void ColorGradient::getStateHidden() {
    state.isEnabled(HIDDEN);
}





