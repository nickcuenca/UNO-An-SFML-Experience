//
// Created by Nicolas Cuenca on 11/23/2020.
//

#ifndef FINAL_PROJECT_UNOGAME_H
#define FINAL_PROJECT_UNOGAME_H
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "PlayerLinkedList.h"
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "SplashScreen.h"
#include <vector>
#include <SFML/Audio.hpp>


class UnoGame {
public:
    void run();
    //Precondition: UnoGame is fully loaded for to run the game.
    //Postcondition: Function runs the whole game.
    UnoGame();
    //Precondition: UnoGame object ready.
    //Postcondition: Default constructor.
    void viewTopCard(PlayerLinkedList &list, DiscardPile dPile, Deck deck, bool &begin);
    //Precondition: A type of playerlinkedlist with a pile and deck is made.
    //Postcondition: Returns what card is on top of the current made classes.
    void playSong();
    //Precondition: A type of song object is made.
    //Postcondition: Plays a song.
    void runSplashScreen();
    //Precondition: A type of splash screen object is made
    //Postcondition: Function runs the splash screen class.
    void gameOver(Player *currPlayer, sf::Sprite bckg);
    //Precondition: Game runs from run(); function
    //Postcondition: Determines when a player reaches one card. Ends the game when it does.
    void drawBoard(PlayerLinkedList list, Player *nextPlayer, sf::Sprite bckg, bool skipped);
private:
    sf::RenderWindow window;
    sf::SoundBuffer buffer1;
    sf::Sound backgroundSong;
    DiscardPile disPile;
    void refillDeck(Deck d, DiscardPile dp);
    //Precondition: A type of deck and discardPile object are made
    //Postcondition: function checks if the deck is empty, then recycls the discardpiles cards into the deck.
};


#endif //FINAL_PROJECT_UNOGAME_H
