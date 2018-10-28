//
// Created by mariano on 27/10/18.
//

#include "PantallaP.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void PantallaP::pantallaP() {




    unsigned int Ancho = 1200u;
    unsigned int Alto = 600u;

    int posX = 0;
    int posY = 30;


//

    sf::RenderWindow window(sf::VideoMode(Ancho, Alto), "League of Gems");


      while (window.isOpen()){
        sf::Event evento;
        while (window.pollEvent(evento)){
            switch (evento.type){
                case sf::Event::Closed:
                    window.close();
                    break;


                    }
            }
        }

        window.clear();
        window.display();
    }




