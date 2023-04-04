//
// Created by Alex on 3/20/2022.
//

#include "MultiText.h"

MultiText::MultiText()
{
    font.loadFromFile("OpenSans-Bold.ttf");
    letter.setFont(font);

    letter.setCharacterSize(50);
    letter.setPosition(x, y);
    letter.setFillColor(sf::Color::White);

    blinkingLine.setFont(font);
    blinkingLine.setString("|");
    blinkingLine.setCharacterSize(50);
    blinkingLine.setFillColor(sf::Color::White);
}

void MultiText::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(canType)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
        {
            if(event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::A:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('A');
                        letters.push_back(letter);

                        break;
                    case sf::Keyboard::B:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('B');

                        letters.push_back(letter);

                        break;
                    case sf::Keyboard::C:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('C');

                        letters.push_back(letter);

                        break;
                    case sf::Keyboard::D:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('D');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::E:

                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('E');
                        letters.push_back(letter);

                        break;
                    case sf::Keyboard::F:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('F');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::G:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('G');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::H:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('H');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::I:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('I');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::J:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('J');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::K:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('K');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::L:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('L');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::M:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 30, letter.getPosition().y);
                        letter.setString('M');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::N:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 18, letter.getPosition().y);
                        letter.setString('N');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::O:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('O');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::P:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('P');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Q:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 28, letter.getPosition().y);
                        letter.setString('Q');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::R:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 19, letter.getPosition().y);
                        letter.setString('R');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::S:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('S');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::T:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('T');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::U:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 24, letter.getPosition().y);
                        letter.setString('U');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::V:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 19, letter.getPosition().y);
                        letter.setString('V');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::W:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 38, letter.getPosition().y);
                        letter.setString('W');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::X:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('X');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Y:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('Y');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Z:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('Z');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::Num1:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('!');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num2:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('@');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num3:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('#');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num4:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('$');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num5:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('%');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num6:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('^');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num7:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('&');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num8:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('*');
                        letter.setFillColor(sf::Color::Green);

                        letters.push_back(letter);
                        letter.setFillColor(sf::Color::White);
                        break;
                    case sf::Keyboard::Num9:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('(');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::Num0:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString(')');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::BackSlash:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('|');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::Slash:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('?');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::Period:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('>');
                        letter.setFillColor(sf::Color::Green);

                        letters.push_back(letter);
                        letter.setFillColor(sf::Color::White);
                        break;

                    case sf::Keyboard::SemiColon:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString(':');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::LBracket:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('{');

                        letters.push_back(letter);
                        break;
                    case sf::Keyboard::RBracket:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('}');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::Dash:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('_');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::Tilde:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('~');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::Equal:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('+');
                        letter.setFillColor(sf::Color::Green);

                        letters.push_back(letter);
                        letter.setFillColor(sf::Color::White);
                        break;

                    case sf::Keyboard::Quote:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('\"');

                        letters.push_back(letter);
                        break;

                    case sf::Keyboard::Comma:
                        letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                        letter.setString('<');
                        letter.setFillColor(sf::Color::Green);

                        letters.push_back(letter);
                        letter.setFillColor(sf::Color::White);
                        break;
                }
            }
        }

        else if(event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::A:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('a');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::B:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('b');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::C:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('c');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::D:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('d');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::E:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('e');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::F:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('f');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::G:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('g');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::H:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('h');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::I:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('i');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::J:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('j');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::K:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('k');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::L:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('l');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::M:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 30, letter.getPosition().y);
                    letter.setString('m');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::N:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('n');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::O:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('o');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::P:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('p');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::Q:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('q');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::R:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('r');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::S:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('s');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::T:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('t');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::U:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('u');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::V:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('v');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::W:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);

                    letter.setString('w');
                    blinkingLine.setPosition(letter.getPosition().x + 30, letter.getPosition().y);
                    letters.push_back(letter);
                    break;
                case sf::Keyboard::X:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('x');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::Y:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('y');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::Z:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('z');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::Num1:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('1');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);

                    break;
                case sf::Keyboard::Num2:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('2');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num3:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('3');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num4:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('4');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num5:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('5');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num6:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('6');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num7:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('7');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num8:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('8');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num9:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('9');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;
                case sf::Keyboard::Num0:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('0');
                    letter.setFillColor(sf::Color::Red);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;

                case sf::Keyboard::BackSlash:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('\\');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::Slash:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('/');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::Period:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('.');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::SemiColon:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString(';');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::LBracket:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('[');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::RBracket:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString(']');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::Dash:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('-');
                    letter.setFillColor(sf::Color::Green);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;

                case sf::Keyboard::Tilde:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('`');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::Equal:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('=');
                    letter.setFillColor(sf::Color::Green);

                    letters.push_back(letter);
                    letter.setFillColor(sf::Color::White);
                    break;

                case sf::Keyboard::Quote:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString('\'');

                    letters.push_back(letter);
                    break;

                case sf::Keyboard::Comma:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString(',');

                    letters.push_back(letter);
                    break;
                case sf::Keyboard::BackSpace:

                    if(!letters.empty())
                    {
                        letters.pop_back();
                    }


                    if (!letters.empty())
                    {
                        letter = letters.back();
                        blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    }
                    else
                    {
                        letter.setString("");
                        blinkingLine.setPosition(letter.getPosition().x - 10, letter.getPosition().y);
                    }

                    letter.setFillColor(sf::Color::White);
                    break;

                case sf::Keyboard::Space:
                    letter.setPosition(letter.getGlobalBounds().left + letter.getGlobalBounds().width, y);
                    blinkingLine.setPosition(letter.getPosition().x + 15, letter.getPosition().y);
                    letter.setString(' ');

                    letters.push_back(letter);
                    break;
            }
        }
    }

    if (clock.getElapsedTime().asSeconds() > 0.5)
    {
        if (tracker == 0)
        {
            blinkingLine.setFillColor(sf::Color::Black);
            tracker++;
        }
        else
        {
            blinkingLine.setFillColor(sf::Color::White);
            tracker--;
        }
        clock.restart();
    }



}

void MultiText::setPositionText(float x, float y)
{
    this->y = y - 7;
    letter.setPosition(x, y);
    setPositionBlinking(x, y - 7);
}

void MultiText::begin() {

}

void MultiText::end() {

}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(auto iterator = letters.begin(); iterator != letters.end(); iterator++)
    {
        window.draw(*iterator);
    }

    if (canType)
    {
        window.draw(blinkingLine);
    }

}

bool MultiText::checkCanType() {
    return canType;
}

void MultiText::enableType()
{
    canType = true;
}

void MultiText::disableType()
{
    canType = false;
}

void MultiText::setPositionBlinking(float x, float y)
{
    blinkingLine.setPosition(x, y);
}

std::string MultiText::getText() {
    std::vector<Letter> letterlist;
    std::string text = "";

    for(auto iterator = letters.begin(); iterator != letters.end(); iterator++)
    {
        letterlist.push_back(*iterator);
    }

    for (int i = 0; i < letterlist.size(); i++)
    {
        text = text + letterlist[i].getString();
    }

    return text;
}


