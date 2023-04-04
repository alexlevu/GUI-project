#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "ShadowBox.h"
#include "Typing.h"
#include "States.h"
#include "TextInput.h"
#include "MenuOptions.h"
#include "DropDownMenu.h"
#include "Menu.h"
#include "NAryTree.h"
#include "FileItem.h"
#include "FileMenu.h"
#include "LabelMakerScreen.h"
#include "DraggingUI.h"
#include "ColorGradient.h"

int main() {

//    NAryTree tree;
//    std::string path = "folder 0";
//    for(int i=1; i<4; i++)
//    {
//        tree.insert(path, "folder " + std::to_string(i));
//        path += "/folder " + std::to_string(i);
//        std::cout << "Path: " << path << std::endl;
//    }
//
//
//    std::cout << "Tree: " << tree;
//    return 0;

    sf::RenderWindow window({1280, 900, 32}, "SFML Project");
    window.setFramerateLimit(60);

    ColorGradient gradient = ColorGradient("Red", 100, 100);


    LabelMakerScreen screen;
    window.setKeyRepeatEnabled(false);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            screen.addEventHandler(window, event);
            sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);

//            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && screen.getMenu().getMenuList()[2].getGlobalBounds().contains(mousePos))
//            {
//                for (int i = 0; i < screen.getMenu().getMenuList().size(); i++)
//                {
//                    for (int j = 0; j < screen.getMenu().getMenuList()[i].getOptions().size(); j++)
//                    {
//                        if (screen.getMenu().getMenuList()[i].getGlobalBounds().contains(mousePos))
//                        {
//                            if (screen.getMenu().getMenuList()[i].getOptions()[j].getTitle() == "Export Image")
//                            {
//                                sf::Image img = texture.getTexture().copyToImage();
//                                img.saveToFile("MyTexture.png");
//                            }
//                        }
//                    }
//
//                }
//
//            }
        }

        screen.update();

        window.clear(sf::Color::Black);
        window.draw(screen);
        window.display();

    }
//    sf::RectangleShape square;
//    square.setSize({100,100});
//    sf::RenderTexture texture;
//    texture.create(1280,300,32);
//
//
//    while(window.isOpen())
//    {
//        sf::Event event;
//        while(window.pollEvent(event))
//        {
//            if(sf::Event::Closed == event.type)
//                window.close();
//
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == event.type)
//            {
//                sf::Image img = texture.getTexture().copyToImage();
//                img.saveToFile("MyTexture.png");
//            }
//        }
//        texture.clear();
//        texture.draw(screen);
//        texture.display();
//
//        window.clear();
//        //window.draw(sprite);
//        window.display();
//    }

}
