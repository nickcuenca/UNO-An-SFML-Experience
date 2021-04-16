//
// Created by Nicolas Cuenca on 11/25/2020.
//

#include "DiscardPile.h"

DiscardPile::DiscardPile() {

}
bool DiscardPile::acceptCard(Card* c){
    if (dPile.empty()){
      dPile.push(c);
      return true;
    } else{
        Card* top = dPile.top();
        if  (top->getRank() == cv::ranks(13) || top->getRank() == cv::ranks(14)){
            dPile.push(c);
            return true;
        }
        if (top->getColor() == c->getColor() || top->getRank() == c->getRank()){
            dPile.push(c);
            return true;
        }
        if (c->getRank() == cv::ranks(13) || c->getRank() == cv::ranks(14)){
            dPile.push(c);
            return true;
        }
        return false;
    }
}
bool DiscardPile::check(Card* c){
    if (dPile.empty()){
        return true;
    } else{
        Card* top = dPile.top();
        if  (top->getRank() == cv::ranks(13) || top->getRank() == cv::ranks(14)){
            return true;
        }
        if (top->getColor() == c->getColor() || top->getRank() == c->getRank()){
            return true;
        }
        if (c->getRank() == cv::ranks(13) || c->getRank() == cv::ranks(14)){
            return true;
        }
        return false;
    }
}

Card *DiscardPile::getTop() {
    Card* top = dPile.top();
    return top;
}

void DiscardPile::popCard() {
    dPile.pop();
}

bool DiscardPile::isEmpty(){
    return dPile.empty();
}

void DiscardPile::deleteCards(){
    while (!dPile.empty()){
        Card* top = dPile.top();
        dPile.pop();
        delete top;
    }
}
