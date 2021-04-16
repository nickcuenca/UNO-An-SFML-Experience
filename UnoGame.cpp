//
// Created by Nicolas Cuenca on 11/23/2020.
//

#include <iostream>
#include "UnoGame.h"
#include <SFML/Audio.hpp>
#include <zconf.h>
#include <string>
UnoGame::UnoGame() : window({1920, 1080, 32}, "UNO (not official UNO)"){
    buffer1.loadFromFile("kick.wav");
    backgroundSong.setBuffer(buffer1);
    window.setFramerateLimit(30);
    sf::Image Icon;
    if (!Icon.loadFromFile("Unocards/card_back.png")){
        std::cout << "Failed to load.\n";
        return;
    }
    window.setIcon(130, 180, Icon.getPixelsPtr());
}

void UnoGame::runSplashScreen() {
    SplashScreen spScreen;
    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
                if(650 <  mpos.x && 775 < mpos.y &&  mpos.x < 1250 && mpos.y < 1025){
                    return;
                }
            }
        }
        playSong();
        window.clear();
        window.draw(spScreen);
        window.display();
    }


}
void UnoGame::run() {
    runSplashScreen();
    sf::Texture bg;
    if (!bg.loadFromFile("bckg.jpg")) {
        std::cout << "Failed to load.\n";
    }
    sf::Sprite bckg;
    sf::Texture cardbg;
    bckg.setTexture(bg);
    bckg.setScale(1, 1);


    int playerNums = 3;
    Deck deck;
    Player *p;
    Player *head = new Player(1);
    p = head;

    int count = 0;
    while (count < playerNums) {
        for (int i = 0; i <  7; i++) {
            p->addCardToHand(deck.popCard());
        }
        count++;

        if (count != playerNums) {
            p->setNextPlayer(new Player(p->getId() + 1));
            p = p->getNextPlayer();
        }
    }
    p->setNextPlayer(head);
    disPile.acceptCard(deck.popCard());
    PlayerLinkedList list(head);
    int card_accepted;
    Player *currPlayer = list.getCurrentPlayer();
    bool topCardViewed = false;
    bool beginGame = true;
    while (window.isOpen()) {

        currPlayer = list.getCurrentPlayer();
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                for (int i = 0; i < currPlayer->getHand().size(); i++) {
                    sf::Vector2f cardPositions = currPlayer->getHand()[i]->getPosition();
                    if (cardPositions.x < mpos.x && mpos.x < cardPositions.x + 130 && cardPositions.y < mpos.y &&
                        mpos.y < cardPositions.y + 182) {
                        if (disPile.acceptCard(currPlayer->getHand()[i])) {
                            if(currPlayer->getHand()[i]->getRank() == cv::REVERSE){
                                list.reverseList();
                            }
                            currPlayer->removeCard(i);
                            drawBoard(head, currPlayer, bckg, false);
                            sleep(2);
                            if(currPlayer->getHand().size() == 1){
                                gameOver(currPlayer, bckg);
                            }
                            std::cout << currPlayer->getHand().size() << std::endl;
                            currPlayer = currPlayer->getNextPlayer();
                            list.setCurrentPlayer(currPlayer);
                            break;
                        }
                    }
                }

                if ((mpos.x < 200 && mpos.x > 100) && (mpos.y > 575 && mpos.y < 675)){
  //                  refillDeck(deck, disPile);
                    currPlayer->addCardToHand(deck.popCard());
                    currPlayer = currPlayer->getNextPlayer();
                    list.setCurrentPlayer(currPlayer);
                }

            }
        }

        if (currPlayer != list.getFirst()) {
            topCardViewed = false;
            Player* originalPlayer = list.getCurrentPlayer();
            viewTopCard(list, disPile, deck, beginGame);
            currPlayer = list.getCurrentPlayer();
            if (originalPlayer != currPlayer){
                drawBoard(list, originalPlayer, bckg, true);
                beginGame = true;
                sleep(4);
            }

            if(currPlayer == list.getFirst()){
                continue;
            }
            bool accepted = false;
            for (int i = 0; i < currPlayer->getHand().size(); i++) {
                if (disPile.check(currPlayer->getHand()[i])) {
                    accepted = true;
                    drawBoard(list,currPlayer, bckg, false);
                    for (int j = 0; j < 5; j++){
                        currPlayer->getHand()[i]->setPosition(1500 - j * 250, 250);
                        window.draw(*currPlayer->getHand()[i]);
                        window.display();
                        sleep(0.5);
                        drawBoard(list, currPlayer, bckg, false);
                    }
                    window.clear();
                    disPile.acceptCard(currPlayer->getHand()[i]);
                    if(currPlayer->getHand()[i]->getRank() == cv::REVERSE){
                        list.reverseList();
                    }
                    currPlayer->removeCard(i);
                    drawBoard(list,currPlayer, bckg, false);
                    sleep(2);
                    break;
                }
            }

            if(currPlayer->getHand().size() == 1){
                gameOver(currPlayer, bckg);
            }

            if (!accepted) {
                drawBoard(list, currPlayer, bckg, true);
//                refillDeck(deck, disPile);
                sleep(2);
                currPlayer->addCardToHand(deck.popCard());
            }

            currPlayer = currPlayer->getNextPlayer();
            list.setCurrentPlayer(currPlayer);
        } else {
            if(!topCardViewed) {
                viewTopCard(list, disPile, deck, beginGame);
                currPlayer = list.getCurrentPlayer();
                topCardViewed = true;
                if (head != currPlayer){
                    drawBoard(list, head, bckg, true);
                    sleep(4);
                    beginGame = true;
                }
            }
        }

        drawBoard(list,currPlayer, bckg, false);


    }

    disPile.deleteCards();
    deck.deleteCards();
    list.deletePlayers();

}

void UnoGame::drawBoard(PlayerLinkedList lst, Player *curr, sf::Sprite bckg, bool skipped = false){
    window.clear();

    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
    sf::Font skipFont;
    sf::Text text;
    sf::Texture pic;
    pic.loadFromFile("funnymonke.jpg");
    sf::Texture* pointerPic = &pic;
    sf::RectangleShape signature;
    signature.setTexture(pointerPic);
    signature.setSize({500, 500});
    signature.setPosition(1400, 560);
    signature.setOutlineColor(sf::Color::White);
    signature.setOutlineThickness(5);
    skipFont.loadFromFile("OpenSans-Bold.ttf");
    text.setFont(skipFont);
    text.setString("SKIP");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(125, 600);
    rectangle.setPosition(100, 575);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(5);

    window.draw(bckg);
    window.draw(signature);
    disPile.getTop()->setPosition(500, 250);
    sf::Text playerDirections;
    playerDirections.setFont(skipFont);
    std::string stringForDirection;
    if(skipped && lst.getFirst() == curr){
        stringForDirection = "You skipped.";
    } else if(skipped){
        stringForDirection = "Player " + std::to_string(curr->getId()) + " skipped.";
    } else if (lst.getFirst() != curr){
        stringForDirection = "Player " + std::to_string(curr->getId()) + " is playing..";
    } else {
        stringForDirection = "You are playing...";
    }

    playerDirections.setString(stringForDirection);
    playerDirections.setCharacterSize(100);
    playerDirections.setPosition(900, 400);
    playerDirections.setFillColor(sf::Color::White);
    playerDirections.setOutlineColor(sf::Color::Black);
    playerDirections.setOutlineThickness(5);

    window.draw(playerDirections);
    window.draw(rectangle);
    window.draw(text);
    window.draw(*disPile.getTop());
    for (int i = 0; i < lst.getFirst()->getHand().size(); i++) {
        lst.getFirst()->getHand()[i]->setPosition( 150 * i, 750);
        window.draw(*lst.getFirst()->getHand()[i]);
    }
    window.display();
}


void UnoGame::gameOver(Player *currPlayer, sf::Sprite bckg){

    while(window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Font skipFont;
        sf::Text text;
        skipFont.loadFromFile("OpenSans-Bold.ttf");
        std::string winString = "UNO!!!!!!!!!! Player " + std::to_string(currPlayer->getId()) + " won!!!!!";
        sf::Text playerDirections;
        playerDirections.setFont(skipFont);
        playerDirections.setString(winString);
        playerDirections.setCharacterSize(110);
        playerDirections.setPosition(200, 400);
        playerDirections.setFillColor(sf::Color::Yellow);
        playerDirections.setOutlineColor(sf::Color::White);
        playerDirections.setOutlineThickness(5);
        window.draw(playerDirections);
        window.display();


    }

}



void UnoGame::viewTopCard(PlayerLinkedList &list, DiscardPile dPile, Deck deck, bool &begin) {
    if(begin){
        begin = false;
        return;
    }

    if (dPile.getTop()->getRank() == cv::SKIP){
        list.setCurrentPlayer(list.getCurrentPlayer()->getNextPlayer());
    }
    if(dPile.getTop() -> getRank() == cv::DRAW_TWO){
        if(deck.size() < 2){
            refillDeck(deck, dPile);
        }
        list.getCurrentPlayer()->addCardToHand(deck.popCard());
        list.getCurrentPlayer()->addCardToHand(deck.popCard());
        refillDeck(deck, dPile);
    }
    if(dPile.getTop() -> getRank() == cv::DRAW_FOUR_WILD){
        if(deck.size() < 4){
           refillDeck(deck, dPile);
        }
        list.getCurrentPlayer()->addCardToHand(deck.popCard());
        list.getCurrentPlayer()->addCardToHand(deck.popCard());
        list.getCurrentPlayer()->addCardToHand(deck.popCard());
        list.getCurrentPlayer()->addCardToHand(deck.popCard());
        list.setCurrentPlayer(list.getCurrentPlayer()->getNextPlayer());
        refillDeck(deck, dPile);
    }

}

void UnoGame::playSong() {
    backgroundSong.play();
    backgroundSong.setVolume(65);
    backgroundSong.setLoop(true);
}

void UnoGame::refillDeck(Deck d, DiscardPile dp){
    if(d.size() == 0){
        while(!dp.isEmpty()) {
            d.addCard(dp.getTop());
            dp.popCard();
        }
        dp.acceptCard(d.popCard());
    }
}
