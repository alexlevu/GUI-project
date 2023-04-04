//
// Created by Alex on 4/17/2022.
//

#include "Images.h"

std::map<ImageName, sf::Texture> Images::images;

std::string Images::getImagePath(ImageName imageName)
{
    switch(imageName)
    {
        case FILEPIC: return "images/file.png";
        case FOLDER: return "images/folder.png";
    }
}

void Images::loadImage(ImageName imageName)
{
    images[imageName] = sf::Texture();
    images[imageName].loadFromFile(getImagePath(imageName));
}

sf::Texture &Images::getImage(ImageName imageName)
{
    loadImage(imageName);
    return images[imageName];
}