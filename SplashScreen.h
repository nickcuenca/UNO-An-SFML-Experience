//
// Created by Nicolas Cuenca on 12/2/2020.
//

#ifndef FINAL_PROJECT_SPLASHSCREEN_H
#define FINAL_PROJECT_SPLASHSCREEN_H


#include "Image.h"
#include "Background.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SplashScreen : public sf::Drawable {
private:
    sf::Texture picOfLayout, texture, enterButtonTexture, bananaTexture;
    sf::Sprite sprite, banana;
    sf::Font globalFont;
    sf::Text name, className, crn, semester, descriptionOfGame, enterGameString, directions, funky;
    sf::RectangleShape portrait, enterButton;
    sf::SoundBuffer buffer;
    sf::Sound song;

public:
    SplashScreen();
    //Precondition: An object of Splash screen is created
    //Postcondition: Splash Screen Constructor
    std::string getFileName();
    //Precondition: A texture is created
    //Postcondition: Texture loaded up with file from disk.
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    //Precondition: A splash screen object is created
    //Postcondition: Splash Screen can now be drawn on screen.
    void setPortrait();
    //Precondition: A Portrait object is created
    //Postcondition: Portrait is now setup.
    void setName();
    //Precondition: A name object is created.
    //Postcondition: A name is now setup.
    void setClassName();
    //Precondition: A ClassName object is created.
    //Postcondition: A ClassName is now setup.
    void setCrn();
    //Precondition: A CRN object is created.
    //Postcondition: A CRN is now setup.
    void setSemester();
    //Precondition: A Semester object is created.
    //Postcondition: A Semester is now setup.
    void setEnterButton();
    //Precondition: A EnterButton object is created.
    //Postcondition: A EnterButton is now setup.
    void setBanana();
    //Precondition: A Banana object is created.
    //Postcondition: A Banana is now setup.
    void playSong();
    //Precondition: A Song object is created.
    //Postcondition: A Song is now setup.
};


#endif //FINAL_PROJECT_SPLASHSCREEN_H
