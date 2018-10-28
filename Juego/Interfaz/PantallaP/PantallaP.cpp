//
// Created by mariano on 27/10/18.
//

#include "PantallaP.h"
#include "../../Mapa/Mapa.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void PantallaP::pantallaP() {


    Mapa *m = new Mapa();
    m->hacerMapa();
    m->imprimirMapa();

    sf::RenderWindow window(sf::VideoMode(672,672), "League of Gems");
    window.setPosition(sf::Vector2i(0,0));
    while (window.isOpen()){
        sf::Event evento;
        while (window.pollEvent(evento)){
            switch (evento.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (evento.MouseButtonPressed) {
                        std::string x = std::to_string(sf::Mouse::getPosition().x);
                        std::string y = std::to_string(sf::Mouse::getPosition().y);

                        std::string i = std::to_string((sf::Mouse::getPosition().x) / 28);
                        std::string j = std::to_string((sf::Mouse::getPosition().y-50) / 28);

                        std::cout << "pos en x: " << x << ", pos en y: " << y << std::endl;
                        std::cout << "pos en i: " << i << ", pos en j: " << j << std::endl << std::endl;
                    }
            }
            for (int i = 0; i<24;i ++){
                for (int j = 0; j<24; j++){
                    if (m->getDato(i,j)==0){
                        sf::RectangleShape c1;
                        c1.setFillColor(sf::Color::Red);
                        c1.setSize(sf::Vector2f(28,28));
                        c1.setPosition(sf::Vector2f(i*28, j*28));
                        window.draw(c1);
                    }
                }
            }
        }



        window.clear(sf::Color::White);
        window.display();
    }

}


