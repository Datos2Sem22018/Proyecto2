//
// Created by mariano on 28/10/18.
//

#include "Inicio.h"
#include <SFML/Graphics.hpp>


void Inicio::inicio() {


    sf::RenderWindow inicio;
    inicio.setPosition(sf::Vector2i(300,100));
    while (inicio.isOpen()){
        sf::Event evento;
        while (inicio.pollEvent(evento)){
            switch (evento.type){
                case sf::Event::Closed:
                    inicio.close();
                    break;



            }
        }

        inicio.clear(sf::Color::White);
        inicio.display();
    }

}
