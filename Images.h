//
// Created by Alex on 4/17/2022.
//

#ifndef MAIN_CPP_IMAGES_H
#define MAIN_CPP_IMAGES_H

#include <SFML//Graphics.hpp>
#include <map>
#include "ImageName.h"

class Images {
private:
    static std::map<ImageName, sf::Texture> images;
    static std::string getImagePath(ImageName imageName);
    static void loadImage(ImageName imageName);
public:
    static sf::Texture& getImage(ImageName imageName);
};


#endif //MAIN_CPP_IMAGES_H
