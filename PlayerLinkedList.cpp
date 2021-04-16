//
// Created by Nicolas Cuenca on 11/25/2020.
//

#include "PlayerLinkedList.h"
#include <iostream>

PlayerLinkedList::PlayerLinkedList(Player *first) {
    this->first = first;
    this->currentPlayer = first;
}

Player *PlayerLinkedList::getFirst() const {
    return first;
}

Player *PlayerLinkedList::getCurrentPlayer() const {
    return currentPlayer;
}

void PlayerLinkedList::setCurrentPlayer(Player *currentPlayer) {
    PlayerLinkedList::currentPlayer = currentPlayer;
}

void PlayerLinkedList::reverseList() {
    Player *prev = first;
    Player *temp;
    Player *curr = first->getNextPlayer();
    bool visited = false;
    while(!visited || prev != first){
        temp = curr->getNextPlayer();
        curr->setNextPlayer(prev);
        prev = curr;
        curr = temp;
        visited = true;
    }
}

void PlayerLinkedList::deletePlayers() {
    Player *curr = first;
    Player *next;

    int count = 0;
    bool visited = false;
    while(curr != first || !visited ){
        count++;
        curr = curr->getNextPlayer();
        visited = true;
    }

    int delete_until = 0;
    while(delete_until < count){
        std::cout << curr->getId() << std::endl;
        next = curr->getNextPlayer();
        delete curr;
        curr = next;
        delete_until++;
    }
    first = nullptr;
    currentPlayer = nullptr;
}
