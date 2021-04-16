//
// Created by Nicolas Cuenca on 11/25/2020.
//

#ifndef FINAL_PROJECT_DISCARDPILE_H
#define FINAL_PROJECT_DISCARDPILE_H
#include <stack>
#include "Card.h"
#include "Deck.h"

class DiscardPile {
private:
    std::stack<Card*> dPile;
public:
    DiscardPile();
    //Precondition: An object of discard pile is created
    //Postcondition: Default constructor for discardpile is created.
    bool acceptCard(Card* c);
    //Precondition: Discard pile made. No functions yet.
    //Postcondition: Algorithm to make sure players can play the correct card.
    Card* getTop();
    //Precondition: Discard pile made. No functions yet.
    //Postcondition: Gets the card on top of the discardPile
    void popCard();
    //Precondition: Discard pile made. No functions yet.
    //Postcondition: Pops a card from the dPile.
    bool check(Card *c);
    //Precondition: Discard pile made. No functions yet.
    //Postcondition: Checks what type of card was played.
    bool isEmpty();
    //Precondition: Discard pile made. No functions yet.
    //Postcondition: Function checks if Dpile is empty.
    void deleteCards();
    //Precondition: Discard pile made. No functions yet.
    //Postcondition: Deletes a card form DPile
};


#endif //FINAL_PROJECT_DISCARDPILE_H
