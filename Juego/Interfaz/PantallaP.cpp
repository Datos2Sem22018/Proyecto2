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

    sf::RenderWindow window(sf::VideoMode(Ancho, Alto), "Tuto");




    sf::RectangleShape cuadrado1;
    sf::RectangleShape cuadrado2;
    sf::RectangleShape cuadrado3;
    sf::RectangleShape cuadrado4;
    sf::RectangleShape cuadrado5;
    sf::RectangleShape cuadrado6;
    sf::RectangleShape cuadrado7;
    sf::RectangleShape cuadrado8;
    sf::RectangleShape cuadrado9;
    sf::RectangleShape cuadrado10;
    sf::RectangleShape cuadrado11;
    sf::RectangleShape cuadrado12;
    sf::RectangleShape cuadrado13;
    sf::RectangleShape cuadrado14;
    sf::RectangleShape cuadrado15;

    sf::Vector2f tamanio(32,28);

    cuadrado1.setSize(tamanio);
    cuadrado2.setSize(tamanio);
    cuadrado3.setSize(tamanio);
    cuadrado4.setSize(tamanio);
    cuadrado5.setSize(tamanio);
    cuadrado6.setSize(tamanio);
    cuadrado7.setSize(tamanio);
    cuadrado8.setSize(tamanio);
    cuadrado9.setSize(tamanio);
    cuadrado10.setSize(tamanio);
    cuadrado11.setSize(tamanio);
    cuadrado12.setSize(tamanio);
    cuadrado13.setSize(tamanio);
    cuadrado14.setSize(tamanio);
    cuadrado15.setSize(tamanio);


    cuadrado1.setPosition(posX+35,posY);
    cuadrado2.setPosition(posX+70,posY);
    cuadrado3.setPosition(posX+105,posY);
    cuadrado4.setPosition(posX+140,posY);
    cuadrado5.setPosition(posX+175,posY);

    cuadrado6.setPosition(posX+35,posY+30);
    cuadrado7.setPosition(posX+70,posY+30);
    cuadrado8.setPosition(posX+105,posY+30);
    cuadrado9.setPosition(posX+140,posY+30);
    cuadrado10.setPosition(posX+175,posY+30);

    cuadrado11.setPosition(posX+35,posY+60);
    cuadrado12.setPosition(posX+70,posY+60);
    cuadrado13.setPosition(posX+105,posY+60);
    cuadrado14.setPosition(posX+140,posY+60);
    cuadrado15.setPosition(posX+175,posY+60);




    cuadrado1.setFillColor(sf::Color::Green);
    cuadrado2.setFillColor(sf::Color::Green);
    cuadrado3.setFillColor(sf::Color::Green);
    cuadrado4.setFillColor(sf::Color::Green);
    cuadrado5.setFillColor(sf::Color::Green);
    cuadrado6.setFillColor(sf::Color::Green);
    cuadrado7.setFillColor(sf::Color::Green);
    cuadrado8.setFillColor(sf::Color::Green);
    cuadrado9.setFillColor(sf::Color::Green);
    cuadrado10.setFillColor(sf::Color::Green);
    cuadrado11.setFillColor(sf::Color::Green);
    cuadrado12.setFillColor(sf::Color::Green);
    cuadrado13.setFillColor(sf::Color::Green);
    cuadrado14.setFillColor(sf::Color::Green);
    cuadrado15.setFillColor(sf::Color::Green);

    while (window.isOpen()){
        sf::Event evento;
        while (window.pollEvent(evento)){
            switch (evento.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (evento.MouseButtonPressed){
                        std::string x = std::to_string(sf::Mouse::getPosition().x);
                        std::string y = std::to_string(sf::Mouse::getPosition().y);
                        std::string i = std::to_string((sf::Mouse::getPosition().y)/32);
                        std::string j = std::to_string((sf::Mouse::getPosition().y)/28);

                        std::cout<<"pos en x: " <<x<<", pos en y: "<<y<<std::endl;
                        std::cout<<"pos en i: " <<i<<", pos en j: "<<j<<std::endl<<std::endl;
                        if (sf::Mouse::getPosition().x > posX)
                            cuadrado1.setPosition(posX+=10, posY);
                        if (sf::Mouse::getPosition().x < posX)
                            cuadrado1.setPosition(posX-=10, posY);
                        if (sf::Mouse::getPosition().y > posY)
                            cuadrado1.setPosition(posX, posY+=10);
                        if (sf::Mouse::getPosition().y < posY)
                            cuadrado1.setPosition(posX, posY-=10);


                    }
            }
        }

        window.clear();


        window.draw(cuadrado1);
        window.draw(cuadrado2);
        window.draw(cuadrado3);
        window.draw(cuadrado4);
        window.draw(cuadrado5);
        window.draw(cuadrado6);
        window.draw(cuadrado7);
        window.draw(cuadrado8);
        window.draw(cuadrado9);
        window.draw(cuadrado10);
        window.draw(cuadrado11);
        window.draw(cuadrado12);
        window.draw(cuadrado13);
        window.draw(cuadrado14);
        window.draw(cuadrado15);
        window.display();
    }


}

