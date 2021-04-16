//
// Created by Nicolas Cuenca on 11/25/2020.
//

#ifndef FINAL_PROJECT_DECK_H
#define FINAL_PROJECT_DECK_H
#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card*> deck;
public:
    Deck();
    //Precondition: A object of deck is created
    //Postcondition: Default constructor made for deck
    void shuffle();
    //Precondition: Deck made. No functions created for it yet.
    //Postcondition: Shuffle allows the deck to be shuffled.
    Card* popCard();
    //Precondition: Deck made. No functions created for it yet.
    //Postcondition: pops a card out of the deck.
    void addCard(Card* c);
    //Precondition: Deck made. No functions created for it yet.
    //Postcondition: adds a card into the deck
    int size() const;
    //Precondition: Deck made. No functions created for it yet.
    //Postcondition: gets size of deck.
    void deleteCards();
    //Precondition:Deck made. No functions created for it yet.
    //Postcondition: deletes a card from the deck.
};


#endif //FINAL_PROJECT_DECK_H
