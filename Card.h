//
// Created by Nicolas Cuenca on 11/25/2020.
//

#ifndef FINAL_PROJECT_CARD_H
#define FINAL_PROJECT_CARD_H
#include "CardVariables.h"
#include "Background.h"
#include <SFML/Graphics.hpp>
#include "Image.h"
class Card : public sf::Drawable {
private:
    cv::colors _color;
    cv::ranks _rank;
    Background background;
    Image image;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    cv::colors getColor() const;
    //Precondition: SFML Card created
    //Postcondition: Card color is returned to the card.
    cv::ranks getRank() const;
    //Precondition: SFML Card created
    //Postcondition: Card rank is returned to the card.
    Card(cv::colors colors, cv::ranks ranks);
    //Precondition: Card object is created.
    //Postcondition: Card object can be created witha  certain color or a rank.
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    //Precondition: Card SFML object created
    //Postcondition: Card can now be drawn by using draw function
    std::string getFileName();
    //Precondition: Card object gets created that needs a rnk
    //Postcondition: A type of PNG gets chosen based off of the cards rank or color.
    void setPosition(float x, float y);
    //Precondition: Card object is created
    //Postcondition: Position for the card object can now be set.
    sf::Vector2f getPosition();
    //Precondition: Card object is created
    //Postcondition: Position for the card object can now be gotten (bounds).
};


#endif //FINAL_PROJECT_CARD_H
