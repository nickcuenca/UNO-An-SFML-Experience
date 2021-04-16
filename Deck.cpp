//
// Created by Nicolas Cuenca on 11/25/2020.
//

#include <algorithm>
#include "Deck.h"
Deck::Deck() {
    for (int i = 0; i < 4 ; i++){
        deck.push_back(new Card(cv::colors(i), cv::ranks(0)));
        for (int j = 1; j <= 12; j++) {
            deck.push_back(new Card(cv::colors(i), cv::ranks(j)));
            deck.push_back(new Card(cv::colors(i), cv::ranks(j)));
        }
        deck.push_back(new Card(cv::colors(4), cv::ranks(13)));
        deck.push_back(new Card(cv::colors(4), cv::ranks(14)));
    }
    shuffle();
}

void Deck::shuffle() {
    std::random_shuffle(deck.begin(), deck.end());
}

int Deck::size() const{
    return deck.size();
}

Card* Deck::popCard(){
    Card* c = deck.back();
    deck.pop_back();
    return c;
}

void Deck::addCard(Card * c) {
    deck.push_back(c);
    shuffle();
}

void Deck::deleteCards(){
    for (Card* c : deck) {
        delete c;
    }
}