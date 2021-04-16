//
// Created by Nicolas Cuenca on 11/25/2020.
//

#ifndef FINAL_PROJECT_PLAYERLINKEDLIST_H
#define FINAL_PROJECT_PLAYERLINKEDLIST_H
#include "Player.h"

class PlayerLinkedList {
private:
    Player* first;
    Player* currentPlayer;

public:
    PlayerLinkedList(Player* first);
    Player *getFirst() const;
    Player *getCurrentPlayer() const;
    void setCurrentPlayer(Player *currentPlayer);
    void reverseList();
    void deletePlayers();

};


#endif //FINAL_PROJECT_PLAYERLINKEDLIST_H
