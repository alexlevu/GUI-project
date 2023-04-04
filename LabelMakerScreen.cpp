//
// Created by Alex on 4/24/2022.
//

#include "LabelMakerScreen.h"

LabelMakerScreen::LabelMakerScreen() {

    texture.create(1280,390,32);
    colorChooser.push(colorOption1);
    colorChooser.push(colorOption2);
    colorChooser.push(colorOption3);
    colorChooser.push(colorOption4);
    colorChooser.push(colorOption5);
    colorChooser.push(colorOption6);

    backgroundColor.push(colorOption1);
    backgroundColor.push(colorOption2);
    backgroundColor.push(colorOption3);
    backgroundColor.push(colorOption4);
    backgroundColor.push(colorOption5);
    backgroundColor.push(colorOption6);

    gradientChooser.push(gradientOption1);
    gradientChooser.push(gradientOption2);
    gradientChooser.push(gradientOption3);
    gradientChooser.push(gradientOption4);
    gradientChooser.push(gradientOption5);
    gradientChooser.push(gradientOption6);


    background.setSize(sf::Vector2f(1280, 900));
    background.setFillColor(sf::Color::Black);

    textBackground.setSize(sf::Vector2f(1280, 380));
    textBackground.setFillColor(textBackgroundColor);


    font.loadFromFile("OpenSans-Bold.ttf");
    textDisplay.setFont(font);
    textDisplay.setCharacterSize(50);
    textDisplay.setFillColor(color);
    textDisplay.setString("Text Area");


    xDrag.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 400);
    yDrag.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 430);
    transDrag.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 460);
    shadowDragX.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 490);
    shadowDragY.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 520);
    shadowTrans.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 550);
    fontDrag.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 580);
    skewDrag.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 610);
    backgroundTrans.setPosition(typingBox.getPosition().x, typingBox.getPosition().y + 640);

    //sets all item positions to the middle of the screen
    setOriginPosition();
    addItemsDropDown();

    gradient = ColorGradient("Green", backgroundColor.getGlobalBounds().left + 100, backgroundColor.getGlobalBounds().top - 400);

    xDrag.setScaler(textDisplay.getPosition().x);
    yDrag.setScaler(textDisplay.getPosition().y);
    transDrag.setScaler(color.a);
    fontDrag.setScaler(textDisplay.getCharacterSize());
    skewDrag.setScaler(shadowBox.getSkew());
    backgroundTrans.setScaler(textBackgroundColor.a);

    shadowDragX.setScaler(shadowBox.getPosition().x);
    shadowDragY.setScaler(shadowBox.getPosition().y);
    shadowTrans.setScaler(shadowBox.getTransparency());
}

void LabelMakerScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);

    typingBox.eventHandler(window, event);
    fontChooser.addEventHandler(window, event);
    colorChooser.addEventHandler(window, event);
    backgroundColor.addEventHandler(window, event);
    gradientChooser.addEventHandler(window, event);
    fileMenu.addEventHandler(window, event);


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (backgroundTrans.getGlobalBounds().contains(mousePos))
        {
            backgroundTrans.addEventHandler(window, event);
            textBackgroundColor.a = backgroundTrans.getScaleValue();
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (transDrag.getGlobalBounds().contains(mousePos))
        {
            transDrag.addEventHandler(window, event);
            color.a = transDrag.getScaleValue();
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (skewDrag.getGlobalBounds().contains(mousePos))
        {
            skewDrag.addEventHandler(window, event);
            shadowBox.setSkew(skewDrag.getScaleValue());
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (shadowTrans.getGlobalBounds().contains(mousePos))
        {
            shadowTrans.addEventHandler(window, event);
            shadowBox.setTransparency(shadowTrans.getScaleValue());
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (fontDrag.getGlobalBounds().contains(mousePos))
        {
            fontDrag.addEventHandler(window, event);
            textDisplay.setCharacterSize(fontDrag.getScaleValue());
            shadowBox.setCharacterSize(fontDrag.getScaleValue());
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (xDrag.getGlobalBounds().contains(mousePos) || yDrag.getGlobalBounds().contains(mousePos))
        {
            xDrag.addEventHandler(window, event);
            yDrag.addEventHandler(window, event);
            textDisplay.setPosition(xDrag.getScaleValue(), yDrag.getScaleValue());
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (shadowDragX.getGlobalBounds().contains(mousePos) || shadowDragY.getGlobalBounds().contains(mousePos))
        {
            shadowDragX.addEventHandler(window, event);
            shadowDragY.addEventHandler(window, event);
            shadowBox.setPosition(shadowDragX.getScaleValue(), shadowDragY.getScaleValue());
        }
    }


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !fontChooserState.isEnabled(HIDDEN))
    {
        for (int i = 0; i < fontChooser.getOptions().size(); i++)
        {
            if(fontChooser.getOptions()[i].getGlobalBounds().contains(mousePos))
            {
                if (fontChooser.getOptions()[i].getTitle() == "OpenSans")
                {
                    font.loadFromFile("OpenSans-Bold.ttf");
                    shadowBox.setFont("OpenSans-Bold.ttf");
                }
                else if (fontChooser.getOptions()[i].getTitle() == "Roboto")
                {
                    font.loadFromFile("Roboto-Bold.ttf");
                    shadowBox.setFont("Roboto-Bold.ttf");
                }
                else if (fontChooser.getOptions()[i].getTitle() == "Lato")
                {
                    font.loadFromFile("Lato-Bold.ttf");
                    shadowBox.setFont("Lato-Bold.ttf");
                }
            }
        }
    }


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !colorChooserState.isEnabled(HIDDEN))
    {
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        for (int i = 0; i < colorChooser.getOptions().size(); i++)
        {
            if(colorChooser.getOptions()[i].getGlobalBounds().contains(mousePos))
            {
                if (colorChooser.getOptions()[i].getTitle() == "White")
                {
                    color = sf::Color::White;
                    shadowBox.setColor(sf::Color::White);
                }
                else if (colorChooser.getOptions()[i].getTitle() == "Green")
                {
                    color = sf::Color::Green;
                    shadowBox.setColor(sf::Color::Green);

                }
                else if (colorChooser.getOptions()[i].getTitle() == "Red")
                {
                    color = sf::Color::Red;
                    shadowBox.setColor(sf::Color::Red);
                }

                else if (colorChooser.getOptions()[i].getTitle() == "Blue")
                {
                    color = sf::Color::Blue;
                    shadowBox.setColor(sf::Color::Blue);
                }
                else if (colorChooser.getOptions()[i].getTitle() == "Cyan")
                {
                    color = sf::Color::Cyan;
                    shadowBox.setColor(sf::Color::Cyan);
                }
                else if (colorChooser.getOptions()[i].getTitle() == "Yellow")
                {
                    color = sf::Color::Yellow;
                    shadowBox.setColor(sf::Color::Yellow);

                }
                else if (colorChooser.getOptions()[i].getTitle() == "Magenta")
                {
                    color = sf::Color::Magenta;
                    shadowBox.setColor(sf::Color::Magenta);
                }
                else if (colorChooser.getOptions()[i].getTitle() == "Black")
                {
                    color = sf::Color::Black;
                    shadowBox.setColor(sf::Color::Black);

                }
                else if (colorChooser.getOptions()[i].getTitle() == "Gray")
                {
                    color = sf::Color(162, 162, 162);
                    shadowBox.setColor(sf::Color(162, 162, 162));

                }
            }
        }
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !gradientChooserState.isEnabled(HIDDEN))
    {
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        for (int i = 0; i < gradientChooser.getOptions().size(); i++)
        {
            if(gradientChooser.getOptions()[i].getGlobalBounds().contains(mousePos))
            {
                if (gradientChooser.getOptions()[i].getTitle() == "White")
                {
                    gradient.setColor("Gray");
                }
                else if (gradientChooser.getOptions()[i].getTitle() == "Green")
                {
                    gradient.setColor("Green");
                }
                else if (gradientChooser.getOptions()[i].getTitle() == "Red")
                {
                    gradient.setColor("Red");
                }

                else if (gradientChooser.getOptions()[i].getTitle() == "Blue")
                {
                    gradient.setColor("Blue");
                }
                else if (gradientChooser.getOptions()[i].getTitle() == "Cyan")
                {
                    gradient.setColor("Cyan");
                }
                else if (gradientChooser.getOptions()[i].getTitle() == "Yellow")
                {
                    gradient.setColor("Yellow");

                }
                else if (gradientChooser.getOptions()[i].getTitle() == "Magenta")
                {
                    gradient.setColor("Magenta");
                }
                else if (gradientChooser.getOptions()[i].getTitle() == "Black")
                {
                    gradient.setColor("Gray");

                }
                else if (gradientChooser.getOptions()[i].getTitle() == "Gray")
                {
                    gradient.setColor("Gray");

                }
            }
        }
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !backgroundColorStates.isEnabled(HIDDEN))
    {
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        for (int i = 0; i < backgroundColor.getOptions().size(); i++)
        {
            if(backgroundColor.getOptions()[i].getGlobalBounds().contains(mousePos))
            {
                if (backgroundColor.getOptions()[i].getTitle() == "White")
                {
                    textBackgroundColor = sf::Color::White;
                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Green")
                {
                    textBackgroundColor = sf::Color::Green;
                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Red")
                {
                    textBackgroundColor = sf::Color::Red;

                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Blue")
                {
                    textBackgroundColor = sf::Color::Blue;
                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Cyan")
                {
                    textBackgroundColor = sf::Color::Cyan;

                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Yellow")
                {
                    textBackgroundColor = sf::Color::Yellow;

                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Magenta")
                {
                    textBackgroundColor = sf::Color::Magenta;

                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Black")
                {
                    textBackgroundColor = sf::Color::Black;

                }
                else if (backgroundColor.getOptions()[i].getTitle() == "Gray")
                {
                    textBackgroundColor = sf::Color(162, 162, 162);

                }
            }
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fileMenu.getMenuList()[0].getOptions()[3].getGlobalBounds().contains(mousePos))
    {
//        for (int i = 0; i < fileMenu.getMenuList().size(); i++)
//        {
//            for (int j = 0; j < fileMenu.getMenuList()[i].getOptions().size(); j++)
//            {
//                if (fileMenu.getMenuList()[i].getGlobalBounds().contains(mousePos))
//                {
//                    if (fileMenu.getMenuList()[i].getOptions()[j].getTitle() == "Quit")
//                    {
//                        exit(0);
//                    }
//                }
//            }
//
//        }
        exit(0);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fileMenu.getMenuList()[2].getOptions()[0].getGlobalBounds().contains(mousePos))
    {
//        for (int i = 0; i < fileMenu.getMenuList().size(); i++)
//        {
//            for (int j = 0; j < fileMenu.getMenuList()[i].getOptions().size(); j++)
//            {
//                if (fileMenu.getMenuList()[i].getGlobalBounds().contains(mousePos))
//                {
//                    if (fileMenu.getMenuList()[i].getOptions()[j].getTitle() == "Export Image")
//                    {
//                        sf::Image img = texture.getTexture().copyToImage();
//                        img.saveToFile("MyTexture.png");
//                    }
//                }
//            }
//
//        }
        sf::Image img = texture.getTexture().copyToImage();
        img.saveToFile("MyTexture.png");

    }
    fontChooserState = fontChooser.getStates();
    colorChooserState = colorChooser.getStates();
    backgroundColorStates = backgroundColor.getStates();
}

void LabelMakerScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(textBackground);
    window.draw(fileMenu);
    window.draw(textDisplay);
    window.draw(typingBox);
    window.draw(shadowBox);
    window.draw(fontChooser);
    window.draw(colorChooser);
    window.draw(backgroundColor);
    window.draw(xDrag);
    window.draw(yDrag);
    window.draw(transDrag);
    window.draw(shadowDragX);
    window.draw(shadowDragY);
    window.draw(shadowTrans);
    window.draw(fontDrag);
    window.draw(skewDrag);
    window.draw(backgroundTrans);
    window.draw(gradientChooser);
    window.draw(gradient);

}

void LabelMakerScreen::update() {
    typingBox.update();
    textDisplay.setString(typingBox.getText());
    textDisplay.setFillColor(color);
    textBackground.setFillColor(textBackgroundColor);

    fileMenu.update();
    shadowBox.setString(typingBox.getText());
    shadowBox.update();

    fontChooser.update();
    colorChooser.update();
    backgroundColor.update();

    xDrag.update();
    yDrag.update();
    transDrag.update();
    shadowDragX.update();
    shadowDragY.update();
    shadowTrans.update();
    fontDrag.update();
    skewDrag.update();
    backgroundTrans.update();
    gradientChooser.update();

    texture.clear();
    texture.draw(textBackground);
    texture.draw(textDisplay);
    texture.draw(shadowBox);
    texture.display();

}

void LabelMakerScreen::setOriginPosition() {
    sf::FloatRect tb = textDisplay.getGlobalBounds();
    sf::FloatRect typeBound = textDisplay.getGlobalBounds();
    sf::FloatRect bb = background.getGlobalBounds();
    sf::FloatRect fb = fontChooser.getGlobalBounds();
    sf::FloatRect cb = colorChooser.getGlobalBounds();
    sf::FloatRect bcb = backgroundColor.getGlobalBounds();
    sf::FloatRect gb = gradientChooser.getGlobalBounds();

    textDisplay.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 150);
    shadowBox.setPosition(textDisplay.getPosition().x, textDisplay.getPosition().y + 100);
    typingBox.setPosition(bb.left + bb.width/2 - typeBound.width/2, bb.top + bb.height/2 - typeBound.height/2);
    fontChooser.setPosition(bb.left + bb.width/2 - fb.width/2 - 50, bb.top + bb.height/2 - fb.height/2);
    colorChooser.setPosition(bb.left + bb.width/2 - fb.width/2 + 150, bb.top + bb.height/2 - fb.height/2);
    backgroundColor.setPosition(bb.left + bb.width/2 - fb.width/2 + 350, bb.top + bb.height/2 - cb.height/2);
    gradientChooser.setPosition(bb.left + bb.width/2 - fb.width/2 + 550, bb.top + bb.height/2 - cb.height/2);

    typingBox.setPosition(background.getGlobalBounds().left + 5, typingBox.getPosition().y);
}

void LabelMakerScreen::addItemsDropDown() {

}

Menu LabelMakerScreen::getMenu() {
    return fileMenu;
}
