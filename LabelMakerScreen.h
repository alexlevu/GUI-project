//
// Created by Alex on 4/24/2022.
//

#ifndef MAIN_CPP_LABELMAKERSCREEN_H
#define MAIN_CPP_LABELMAKERSCREEN_H
#include "FileMenu.h"
#include "TextInput.h"
#include "DropDownMenu.h"
#include <SFML/Graphics.hpp>
#include "DraggingUI.h"
#include "ShadowBox.h"
#include "Menu.h"
#include "ColorGradient.h"

class LabelMakerScreen : public sf::Drawable{
private:
    sf::RectangleShape background;
    sf::RectangleShape textBackground;
    sf::Color textBackgroundColor = sf::Color::Black;
    sf::Text textDisplay;
    sf::Color color = sf::Color::White;
    ShadowBox shadowBox;
    sf::Font font;
    TextInput typingBox;
    DropDownMenu fontChooser = DropDownMenu("OpenSans", "Roboto", "Lato", "Font");
    States fontChooserState;
    Menu fileMenu = Menu(5, 5);

    DropDownMenu colorChooser = DropDownMenu("White", "Green", "Red", "Color");
    States colorChooserState;
    MenuOptions colorOption1 = MenuOptions("Blue");
    MenuOptions colorOption2 = MenuOptions("Cyan");
    MenuOptions colorOption3 = MenuOptions("Yellow");
    MenuOptions colorOption4 = MenuOptions("Magenta");
    MenuOptions colorOption5 = MenuOptions("Black");
    MenuOptions colorOption6 = MenuOptions("Gray");

    DropDownMenu gradientChooser = DropDownMenu("Green", "White", "Red", "Gradient");
    States gradientChooserState;
    MenuOptions gradientOption1 = MenuOptions("Blue");
    MenuOptions gradientOption2 = MenuOptions("Cyan");
    MenuOptions gradientOption3 = MenuOptions("Yellow");
    MenuOptions gradientOption4 = MenuOptions("Magenta");
    MenuOptions gradientOption5 = MenuOptions("Black");
    MenuOptions gradientOption6 = MenuOptions("Gray");

    DropDownMenu backgroundColor = DropDownMenu("Green", "White", "Red", "Background");
    States backgroundColorStates;

    DraggingUI xDrag = DraggingUI("Text X-Axis", 300);
    DraggingUI yDrag = DraggingUI("Text Y-Axis", 300);
    DraggingUI transDrag = DraggingUI("Text Opacity", 300);
    DraggingUI shadowDragX = DraggingUI("Shadow X-Axis", 300);
    DraggingUI shadowDragY = DraggingUI("Shadow Y-Axis", 300);
    DraggingUI shadowTrans = DraggingUI("Shadow Opacity", 300);
    DraggingUI fontDrag = DraggingUI("Font Size", 200);
    DraggingUI skewDrag = DraggingUI("Skew", 200);
    DraggingUI backgroundTrans = DraggingUI("Background Opacity", 300);

    ColorGradient gradient;


    sf::RenderTexture texture;

public:

    LabelMakerScreen();

    void setOriginPosition();
    void addItemsDropDown();

    Menu getMenu();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //MAIN_CPP_LABELMAKERSCREEN_H
