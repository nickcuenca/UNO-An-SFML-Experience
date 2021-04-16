//
// Created by Nicolas Cuenca on 11/25/2020.
//

#include "Player.h"

Player *Player::getNextPlayer() const {
    return nextPlayer;
}

const std::vector<Card *> &Player::getHand() const {
    return hand;
}

void Player::addCardToHand(Card *c) {
    hand.push_back(c);
}

void Player::setNextPlayer(Player *nextPlayer) {
    Player::nextPlayer = nextPlayer;
}

void Player::setHand(const std::vector<Card *> &hand) {
    Player::hand = hand;
}

void Player::removeCard(int i) {
    hand.erase(hand.begin() + i);
}

Player::Player(int i) {
    this->id = i;
}

int Player::getId(){
    return id;
}

Player::~Player() {
    for (Card* c: hand) {
        delete c;
    }
}
