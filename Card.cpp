//
// Created by Nicolas Cuenca on 11/25/2020.
//

#include "Card.h"
#include "SFML/Graphics.hpp"

cv::colors Card::getColor() const {
    return _color;
}

cv::ranks Card::getRank() const {
    return _rank;
}

Card::Card(cv::colors colors, cv::ranks ranks) {
    this->_color = colors;
    this->_rank = ranks;
    this->image = Image(getFileName());
    texture.loadFromFile(getFileName());
    sprite.setTexture(texture);
}

void Card::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(sprite);
}

std::string Card::getFileName(){
    std::string filename = "Unocards/";
    switch (_color){
        case cv::GREEN:
            filename += "green_";
            break;
        case cv::RED:
            filename += "red_";
            break;
        case cv::YELLOW:
                    filename += "yellow_";
            break;
        case cv::BLUE:
                    filename += "blue_";
            break;
        case cv::SPECIAL:
            break;
    }

    switch (_rank){
        case cv::ZERO:
            filename += "0";
            break;
        case cv::ONE:
            filename += "1";
            break;
        case cv::TWO:
            filename += "2";
            break;
        case cv::THREE:
            filename += "3";
            break;
        case cv::FOUR:
            filename += "4";
            break;
        case cv::FIVE:
            filename += "5";
            break;
        case cv::SIX:
            filename += "6";
            break;
        case cv::SEVEN:
            filename += "7";
            break;
        case cv::EIGHT:
            filename += "8";
            break;
        case cv::NINE:
            filename += "9";
            break;
        case cv::SKIP:
            filename += "skip";
            break;
        case cv::REVERSE:
            filename += "reverse";
            break;
        case cv::DRAW_TWO:
            filename += "picker";
            break;
        case cv::WILD:
            filename += "wild_color_changer";
            break;
        case cv::DRAW_FOUR_WILD:
            filename += "wild_pick_four";
            break;
    }
    return filename += ".png";
}
void Card::setPosition(float x, float y){
    sprite.setPosition(x, y);
}

sf::Vector2f Card::getPosition(){
    return sprite.getPosition();
}
