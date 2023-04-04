//
// Created by Alex on 4/17/2022.
//

#include "FileMenu.h"

FileMenu::FileMenu() {

    options.push_back(item1);
    options.push_back(item2);
    options.push_back(item3);

    FileMenuState.enableState(HIDDEN);

    menu.setSize(sf::Vector2f(150, 30));
    menu.setFillColor(sf::Color(128, 128, 128));
    menu.setPosition(100, 100);

    initialX = menu.getPosition().x;
    initialY = menu.getPosition().y + 35;

    for (int i = 0; i < options.size(); i++)
    {
        options[i].setPosition(initialX, initialY);
        initialY += 35;
    }

    font.loadFromFile("OpenSans-Bold.ttf");
    title.setFont(font);
    title.setString("Directory 1");
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);

    menuIcon.setTexture(Images::getImage(FOLDER));
    menuIcon.setScale(0.1, 0.1);


    sf::FloatRect ib = menuIcon.getGlobalBounds();
    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = menu.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
    menuIcon.setPosition(bb.left, bb.top + bb.height/2 - ib.height/2);
}

FileMenu::FileMenu(std::string menuTitle,float x, float y) {

    options.push_back(item1);
    options.push_back(item2);
    options.push_back(item3);

    FileMenuState.enableState(HIDDEN);

    menu.setSize(sf::Vector2f(150, 30));
    menu.setFillColor(sf::Color(128, 128, 128));
    menu.setPosition(x, y);

    initialX = menu.getPosition().x + 30;
    initialY = menu.getPosition().y;

    for (int i = 0; i < options.size(); i++)
    {
        initialY += options[i].getGlobalBounds().height + 5;
        options[i].setPosition(initialX, initialY);

    }

    font.loadFromFile("OpenSans-Bold.ttf");
    title.setFont(font);
    title.setString(menuTitle);
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);

    menuIcon.setTexture(Images::getImage(FOLDER));
    menuIcon.setScale(0.02, 0.02);

    sf::FloatRect ib = menuIcon.getGlobalBounds();
    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = menu.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
    menuIcon.setPosition(bb.left, bb.top + bb.height/2 - ib.height/2);
}

void FileMenu::setPosition(float x, float y) {

}

void FileMenu::setSize(float x, float y) {

}

void FileMenu::push(FileItem item) {

}

sf::FloatRect FileMenu::getGlobalBounds() const {
    return menu.getGlobalBounds();
}

void FileMenu::update() {
    for (int i = 0; i < options.size(); i++)
    {
        options[i].update();
    }

    if (!FileMenuState.isEnabled(HIDDEN))
    {
        menu.setFillColor(sf::Color::Blue);
    }
    else if(FileMenuState.isEnabled(HIDDEN))
    {
        menu.setFillColor(sf::Color(128, 128, 128));
    }
}

void FileMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < options.size(); i++)
    {
        options[i].addEventHandler(window, event);
    }


    if(FileMenuState.isEnabled(HIDDEN))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if(menu.getGlobalBounds().contains(mousePos))
            {
                FileMenuState.disableState(HIDDEN);
            }
        }
    }
    else if(!FileMenuState.isEnabled(HIDDEN))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if(menu.getGlobalBounds().contains(mousePos))
            {
                FileMenuState.enableState(HIDDEN);
            }
        }
    }
}

void FileMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = menu.getTransform();

    if(FileMenuState.isEnabled(HIDDEN))
    {
        window.draw(menu);
        window.draw(title);
        window.draw(menuIcon);
    }

    else if (!FileMenuState.isEnabled(HIDDEN))
    {
        window.draw(menu);
        window.draw(title);
        window.draw(menuIcon);

        for (int i = 0; i < options.size(); i++)
        {
            window.draw(options[i], states);
        }
    }
}
