//
// Created by Nicolas Cuenca on 11/25/2020.
//

#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H
#include <vector>
#include "Card.h"
class Player {
private:
    std::vector<Card*> hand;
    int id;
    Player* nextPlayer;
public:
    Player(int id);
    //Precondition: Object of Player is created
    //Postcondition: Constructor setup with an ID unique to player.
    Player *getNextPlayer() const;
    //Precondition: Type of player is created.
    //Postcondition: Gets the next pointer of a type player. Sees who is playing after current player.
    const std::vector<Card *> &getHand() const;
    //Precondition: Player object created that contains a hand.
    //Postcondition: Gets the players hand and returns what cards the hand is made up of.
    void addCardToHand(Card* c);
    //Precondition: Player object created that contains a hand.
    //Postcondition: Adds a card to player hand.
    void setNextPlayer(Player *nextPlayer);
    //Precondition: Player object created.
    //Postcondition: Sets the function to allow the next player to play their turn.
    void setHand(const std::vector<Card *> &hand);
    //Precondition: Player object created that contains a hand.
    //Postcondition: Allows a players hand to manually be altered to set the hand.
    void removeCard(int i);
    //Precondition:  Player object created that contains a hand.
    //Postcondition: Allows for a card in a players hand to be removed.
    int getId();
    //Precondition: Player made with a specific unique ID
    //Postcondition: Gets the players ID
    ~Player();
};


#endif //FINAL_PROJECT_PLAYER_H
