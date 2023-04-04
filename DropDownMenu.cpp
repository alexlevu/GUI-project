//
// Created by Alex on 4/2/2022.
//

#include "DropDownMenu.h"

DropDownMenu::DropDownMenu()
{
    options.push_back(item1);
    options.push_back(item2);
    options.push_back(item3);
    menuState.enableState(HIDDEN);

    menu.setSize(sf::Vector2f(150, 30));
    menu.setOutlineColor(sf::Color::White);
    menu.setOutlineThickness(5);
    menu.setFillColor(sf::Color::Black);
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
    title.setString(options.front().getTitle());
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);


    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = menu.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);

}
DropDownMenu::DropDownMenu(std::string name, std::string name2, std::string name3, std::string text){

    item1.setText(name);
    item2.setText(name2);
    item3.setText(name3);

    options.push_back(item1);
    options.push_back(item2);
    options.push_back(item3);

    menuState.enableState(HIDDEN);

    menu.setSize(sf::Vector2f(150, 30));
    menu.setOutlineColor(sf::Color::White);
    menu.setOutlineThickness(5);
    menu.setFillColor(sf::Color::Black);
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
    title.setString(options.front().getTitle());
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(25);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(menu.getPosition().x + 5, menu.getPosition().y - menu.getGlobalBounds().height);

    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = menu.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
}

DropDownMenu::DropDownMenu(float x, float y, std::string name, std::string name2, std::string name3)
{
    item1 = MenuOptions(name);
    item2 = MenuOptions(name2);
    item3 = MenuOptions(name3);

    options.push_back(item1);
    options.push_back(item2);
    options.push_back(item3);

    menuState.enableState(HIDDEN);

    menu.setSize(sf::Vector2f(150, 30));
    menu.setOutlineColor(sf::Color::White);
    menu.setOutlineThickness(5);
    menu.setFillColor(sf::Color::Black);
    menu.setPosition(x, y);

    initialX = menu.getPosition().x;
    initialY = menu.getPosition().y;

    for (int i = 0; i < options.size(); i++)
    {
        initialY += options[i].getGlobalBounds().height + 5;
        options[i].setPosition(initialX, initialY);

    }

    font.loadFromFile("OpenSans-Bold.ttf");
    title.setFont(font);
    title.setString(options.front().getTitle());
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);



    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = menu.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
}

void DropDownMenu::update()
{
    for (int i = 0; i < options.size(); i++)
    {
        options[i].update();
    }
}

void DropDownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if (!menuState.isEnabled(HIDDEN))
    {
        for (int i = 0; i < options.size(); i++)
        {
            options[i].addEventHandler(window, event);
        }
    }

    if(menuState.isEnabled(HIDDEN))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if(menu.getGlobalBounds().contains(mousePos))
            {
                menuState.disableState(HIDDEN);
            }
        }
    }
    else if(!menuState.isEnabled(HIDDEN))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if(menu.getGlobalBounds().contains(mousePos))
            {
                menuState.enableState(HIDDEN);
            }
        }
    }


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        for (int i = 0; i < options.size(); i++)
        {
            if(options[i].getGlobalBounds().contains(mousePos) && !menuState.isEnabled(HIDDEN) && !disable)
            {
                menuState.enableState(HIDDEN);
                title.setString(options[i].getTitle());
                snapShot.getSnapshot(options[i].getTitle());
            }
            else if(options[i].getGlobalBounds().contains(mousePos) && disable)
            {
                menuState.enableState(HIDDEN);
                snapShot.getSnapshot(options[i].getTitle());
            }
        }
    }

    if (KeyBoardShortcut::isUndo())
    {
        if(!snapShot.listIsEmpty())
        {
            title.setString(snapShot.getData1());
        }

    }
}

void DropDownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    states.transform = menu.getTransform();

    if(menuState.isEnabled(HIDDEN))
    {
        window.draw(menu);
        window.draw(title);
        window.draw(text);
    }

    else if (!menuState.isEnabled(HIDDEN))
    {
        window.draw(menu);
        window.draw(title);
        window.draw(text);

        for (int i = 0; i < options.size(); i++)
        {
            window.draw(options[i], states);
        }
    }
}

void DropDownMenu::push(MenuOptions item)
{
    item.setPosition(initialX, initialY);
    initialY += item.getGlobalBounds().height + 5;
    options.push_back(item);
}

void DropDownMenu::setSize(float x, float y)
{
    float posY = menu.getPosition().y;

    menu.setSize(sf::Vector2f(x, y));
    title.setCharacterSize(y - 10);

    for (int i = 0; i < options.size(); i++)
    {
        options[i].setSize(x, y);
        posY += options[i].getGlobalBounds().height + 5;
        options[i].setPosition(initialX, posY);
    }
}

void DropDownMenu::setPosition(float x, float y)
{
    menu.setPosition(x, y);

    text.setPosition(menu.getGlobalBounds().left + menu.getGlobalBounds().width/2 - text.getGlobalBounds().width/2, menu.getPosition().y - menu.getGlobalBounds().height);
    initialX = menu.getPosition().x;
    initialY = menu.getPosition().y;

    for (int i = 0; i < options.size(); i++)
    {
        initialY += options[i].getGlobalBounds().height + 5;
        options[i].setPosition(initialX, initialY);
    }

    sf::FloatRect tb = title.getGlobalBounds();
    sf::FloatRect bb = menu.getGlobalBounds();

    title.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
}

sf::FloatRect DropDownMenu::getGlobalBounds() const {
    return menu.getGlobalBounds();
}

std::vector<MenuOptions> DropDownMenu::getOptions() {
    return options;
}

States DropDownMenu::getStates() {
    return menuState;
}

void DropDownMenu::disableMenu() {
    disable = true;
}

void DropDownMenu::setTitle(std::string text) {
    title.setString(text);
}

