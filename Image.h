//
// Created by Nicolas Cuenca on 11/27/2020.
//

#ifndef FINAL_PROJECT_IMAGE_H
#define FINAL_PROJECT_IMAGE_H
#include "SFML/Graphics.hpp"

class Image : public sf::Drawable {
private:
    sf::Sprite bckg;
    sf::Texture bg;
    void init(std::string filename);
    //Precondition: A type of image is created
    //Postcondition: Function initializes the image.
public:
    Image();
    //Precondition: Object of image created
    //Postcondition: Image default constructor
    Image(std::string filename);
    //Precondition: Image object created
    //Postcondition: Constructor with filename created.
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    //Precondition: Image object created
    //Postcondition: Image can be drawn with function
};

#endif //FINAL_PROJECT_IMAGE_H
