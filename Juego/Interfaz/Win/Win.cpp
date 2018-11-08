//
// Created by mariano on 08/11/18.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "Win.h"

void Win::win() {

    //StartW Window
    //Create the Window
    sf::RenderWindow win(sf::VideoMode(600,300), "League of Gems");
    //Position the window in the center of the screen
    win.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width/2)-300,(sf::VideoMode::getDesktopMode().height/2)-150 ));

    //
    sf::Font font;
    if(!font.loadFromFile("../Fonts/evafangoria.ttf"))
    {
        //
    }
    //Title
    sf::Text textWin;
    textWin.setFont(font);
    textWin.setString("Yuo Win");
    textWin.setCharacterSize(50);
    sf::Color color(sf::Color(244, 190, 7));
    textWin.setFillColor(color);
    textWin.setPosition(200,25);


    //
    sf::Text textSpace;
    textSpace.setFont(font);
    textSpace.setString("Press Space to continue...");
    textSpace.setColor(sf::Color(244, 190, 7));
    textSpace.setPosition(250,80);
    textSpace.setCharacterSize(20);



    //infinite loop that is active while the window is open
    while (win.isOpen()){
        sf::Event evento;
        while (win.pollEvent(evento)){
            switch (evento.type){

                //Event that records that the window has been closed
                case sf::Event::Closed:
                    win.close();
                    break;
                case sf::Event::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        win.close();
                        break;
                    }
                    }




            }
        }

        win.draw(textWin);
        win.draw(textSpace);
        win.clear();
        win.display();
    }




