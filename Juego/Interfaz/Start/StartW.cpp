//
// Created by mariano on 28/10/18.
//

#include "StartW.h"
#include "../PrincipalW/PrincipalW.h"
#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * Method that creates the star window
 */
void StartW::startW() {

//StartW Window
    //Create the Window
    sf::RenderWindow startW(sf::VideoMode(600,300), "League of Gems");
    //Position the window in the center of the screen
    startW.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width/2)-300,(sf::VideoMode::getDesktopMode().height/2)-150 ));

    //
    sf::Font font;
    if(!font.loadFromFile("../Fonts/evafangoria.ttf"))
    {
        //
    }
    //Title
    sf::Text textTitle;
    textTitle.setFont(font);
    textTitle.setString("League of Gems");
    textTitle.setCharacterSize(50);
    sf::Color color(sf:: Color::Black);
    textTitle.setFillColor(color);
    textTitle.setPosition(200,25);


    //Menu
    sf::Text textSelectNivel;
    textSelectNivel.setFont(font);
    textSelectNivel.setString("Select the level");
    textSelectNivel.setColor(sf::Color::Black);
    textSelectNivel.setPosition(250,80);
    textSelectNivel.setCharacterSize(20);
    std::string level;

    //Easy
    sf::Text textEasy;
    textEasy.setFont(font);
    textEasy.setString("Easy");
    textEasy.setColor(sf::Color::Black);
    textEasy.setPosition(280,100);
    textEasy.setCharacterSize(30);

    //Easy
    sf::Text textMedium;
    textMedium.setFont(font);
    textMedium.setString("Medium");
    textMedium.setColor(sf::Color::Black);
    textMedium.setPosition(280,130);
    textMedium.setCharacterSize(30);

    //Easy
    sf::Text textHard;
    textHard.setFont(font);
    textHard.setString("Hard");
    textHard.setColor(sf::Color::Black);
    textHard.setPosition(280,160);
    textHard.setCharacterSize(30);


    //Texture
    sf::Texture texture;
    texture.loadFromFile("../Images/StartBG.png");

    //Sprite
    sf::Sprite sprite(texture);

    //infinite loop that is active while the window is open
    while (startW.isOpen()){
        sf::Event evento;
        while (startW.pollEvent(evento)){
            switch (evento.type){

                //Event that records that the window has been closed
                case sf::Event::Closed:
                    startW.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        int mouseXpos = sf::Mouse::getPosition(startW).x;
                        int mouseYpos = sf::Mouse::getPosition(startW).y;
                        if(280<mouseXpos && mouseXpos<320 && 110<mouseYpos && mouseYpos<130){
                            std::cout<<"Easy"<<std::endl;
                            level="Easy";
                        }
                        else if(280<mouseXpos && mouseXpos<340 && 140<mouseYpos && mouseYpos<160){
                            std::cout<<"Medium"<<std::endl;
                            level="Medium";
                        }
                        else if(280<mouseXpos && mouseXpos<320 && 170<mouseYpos && mouseYpos<190){
                            std::cout<<"Hard"<<std::endl;
                            level="Hard";
                        }
                    }


                //Event tha records when the user press a button

            }
        }
        startW.clear(sf::Color(244, 190, 7));
        startW.draw(sprite);
        startW.draw(textTitle);
        startW.draw(textSelectNivel);
        startW.draw(textEasy);
        startW.draw(textMedium);
        startW.draw(textHard);
        startW.display();
    }

}
