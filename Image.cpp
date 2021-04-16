//
// Created by Nicolas Cuenca on 11/27/2020.
//

#include <iostream>
#include "Image.h"
Image::Image() {}
Image::Image(std::string filename){
    init(filename);
}


void Image::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(bckg);
}

void Image::init(std::string filename){
    if (!bg.loadFromFile(filename)){
        std::cout << "Failed to load.\n";
    }
    sf::Sprite bckg;
    bckg.setTexture(bg);
}
