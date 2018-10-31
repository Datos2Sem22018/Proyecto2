//
// Created by mariano on 28/10/18.
//

#include "StartW.h"
#include "../PantallaP/PantallaP.h"
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
    if(!font.loadFromFile("/home/mariano/CLionProjects/Proyecto2/Fonts/evafangoria.ttf"))
    {
        //
    }

    //Text
    sf::Text text;
    text.setFont(font);
    text.setString("Press Space to continue...");
    text.setCharacterSize(50);
    sf::Color color(sf:: Color::Black);
    text.setFillColor(color);
    text.setPosition(150,150);

    //Texture
    sf::Texture texture;
    texture.loadFromFile("/home/mariano/CLionProjects/Proyecto2/Images/StartBG.png");

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

                //Event tha records when the user press a button
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                        startW.close();
                        PantallaP::pantallaP();
                        break;
                    }




            }
        }

        startW.clear(sf::Color(244, 190, 7));
        startW.draw(sprite);
        startW.draw(text);
        startW.display();
    }

}
