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

    int posX=0, posY=0;

    sf::RenderWindow window(sf::VideoMode(672-28,672-28), "League of Gems");
    window.setPosition(sf::Vector2i(0,0));

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(28,28));
    rect.setPosition(sf::Vector2f(posX,posY));
    rect.setFillColor(sf::Color::Green);


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
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        rect.setPosition(sf::Vector2f(posX+=10, posY));
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        rect.setPosition(sf::Vector2f(posX-=10, posY));
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        rect.setPosition(sf::Vector2f(posX, posY+=10));
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        rect.setPosition(sf::Vector2f(posX, posY-=10));
                    }
            }

        }

        window.clear();
        for (int i = 0; i<23;i ++){
            for (int j = 0; j<23; j++){
                if (m->getDato(i,j)==0){
                    sf::RectangleShape c1;
                    c1.setSize(sf::Vector2f(28,28));
                    c1.setPosition(sf::Vector2f(i*28, j*28));
                    c1.setFillColor(sf::Color::Magenta);
                    window.draw(c1);
                }
                else if(m->getDato(i,j)==1){
                    sf::RectangleShape c1;
                    c1.setSize(sf::Vector2f(28,28));
                    c1.setPosition(sf::Vector2f(i*28, j*28));
                    c1.setFillColor(sf::Color::White);
                    window.draw(c1);
                }
            }
        }



        window.draw(rect);
        window.display();
    }

}

void Ruta(){


}


