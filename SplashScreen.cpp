//
// Created by Nicolas Cuenca on 12/2/2020.
//

#include "SplashScreen.h"
#include <iostream>
SplashScreen::SplashScreen() {
    texture.loadFromFile(getFileName());
    sprite.setTexture(texture);
    globalFont.loadFromFile("OpenSans-Bold.ttf");
    buffer.loadFromFile("two.wav");
    song.setBuffer(buffer);
    setName();
    setClassName();
    setCrn();
    setSemester();
    setPortrait();
    setEnterButton();
    setBanana();
    playSong();
}

std::string SplashScreen::getFileName() {
    std::string filename = "unosplash.jpg";
    return filename;
}

void SplashScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(sprite);
    window.draw(banana);
    window.draw(name);
    window.draw(className);
    window.draw(crn);
    window.draw(semester);
    window.draw(portrait);
    window.draw(descriptionOfGame);
    window.draw(enterButton);
    window.draw(enterGameString);
    window.draw(directions);
    window.draw(funky);
}
void SplashScreen::setPortrait() {
    picOfLayout.loadFromFile("funnymonke.jpg");
    sf::Texture* pointerPic = &picOfLayout;
    this->portrait.setTexture(pointerPic);
    this->portrait.setSize({500, 500});
    this->portrait.setPosition(1400, 20);
    this->descriptionOfGame.setFont(globalFont);
    this->descriptionOfGame.setString("From Nick Cuenca Studios, the greatest \nthing to ever happen in all of 2020, UNO.\n\n\nRated 9.42 bananas\nout of 10 by BLOCKBUSTER.\n\n\n\nPlease click on the 'ENTER GAME' button\nto start the game!");
    this->name.setCharacterSize(25);
    this->descriptionOfGame.setFillColor(sf::Color::White);
    this->descriptionOfGame.setPosition(1300, 600);
    this->descriptionOfGame.setOutlineColor(sf::Color::Black);
    this->descriptionOfGame.setOutlineThickness(5);
    this->portrait.setOutlineColor(sf::Color::White);
    this->portrait.setOutlineThickness(5);
}
void SplashScreen::setName() {
    this->name.setFont(globalFont);
    this->name.setString("Nicolas Cuenca");
    this->name.setCharacterSize(50);
    this->name.setFillColor(sf::Color::White);
    this->name.setPosition(70, 100);
    this->name.setOutlineColor(sf::Color::Black);
    this->name.setOutlineThickness(5);
}
void SplashScreen::setClassName() {
    this->className.setFont(globalFont);
    this->className.setString("CS 003A: Intro to Object\nOriented Programming \nC++");
    this->className.setCharacterSize(35);
    this->className.setFillColor(sf::Color::White);
    this->className.setPosition(70, 200);
    this->className.setOutlineColor(sf::Color::Black);
    this->className.setOutlineThickness(5);
}
void SplashScreen::setCrn() {
    this->crn.setFont(globalFont);
    this->crn.setString("CRN: 73275");
    this->crn.setCharacterSize(35);
    this->crn.setFillColor(sf::Color::White);
    this->crn.setPosition(70, 400);
    this->crn.setOutlineColor(sf::Color::Black);
    this->crn.setOutlineThickness(5);
}
void SplashScreen::setSemester() {
    this->semester.setFont(globalFont);
    this->semester.setString("Fall 2020");
    this->semester.setCharacterSize(35);
    this->semester.setFillColor(sf::Color::White);
    this->semester.setPosition(70, 500);
    this->semester.setOutlineColor(sf::Color::Black);
    this->semester.setOutlineThickness(5);
}

void SplashScreen::setEnterButton() {
    this->enterButtonTexture.loadFromFile("enterButtonTexture.jpg");
    sf::Texture* pointerPic = &enterButtonTexture;
    this->enterButton.setTexture(pointerPic);
    this->enterButton.setSize({600, 250});
    this->enterButton.setPosition(650, 775);
    this->enterButton.setOutlineColor(sf::Color::White);
    this->enterButton.setOutlineThickness(5);

    this->enterGameString.setFont(globalFont);
    this->enterGameString.setString("ENTER\nGAME");
    this->enterGameString.setCharacterSize(100);
    this->enterGameString.setFillColor(sf::Color::White);
    this->enterGameString.setPosition(775, 770);
    this->enterGameString.setOutlineColor(sf::Color::Black);
    this->enterGameString.setOutlineThickness(5);

    this->directions.setFont(globalFont);
    this->directions.setString("Please click anywhere on this button! ----->");
    this->directions.setCharacterSize(25);
    this->directions.setFillColor(sf::Color::White);
    this->directions.setPosition(95, 900);
    this->directions.setOutlineColor(sf::Color::Black);
    this->directions.setOutlineThickness(5);
}

void SplashScreen::playSong() {
    song.play();
    song.setPlayingOffset(sf::seconds(4.f));
    song.setVolume(35.f);
    song.setLoop(true);
}

void SplashScreen::setBanana() {
    this->bananaTexture.loadFromFile("banana.png");
    this->banana.setTexture(bananaTexture);
    this->banana.rotate(45);
    this->banana.setPosition(250, -165);
    this->banana.setScale(0.8, 0.8);
    this->funky.setFont(globalFont);
    this->funky.setString("LET'S GET FUNKY!");
    this->funky.setCharacterSize(45);
    this->funky.setFillColor(sf::Color::Yellow);
    this->funky.setPosition(750, 50);
    this->funky.setOutlineColor(sf::Color::Black);
    this->funky.setOutlineThickness(5);
}


