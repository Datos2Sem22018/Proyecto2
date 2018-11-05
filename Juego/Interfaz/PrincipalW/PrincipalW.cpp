//
// Created by mariano on 27/10/18.
//

#include "PrincipalW.h"
#include "../../Mapa/Mapa.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void PrincipalW::principalW() {


    Mapa *m = new Mapa();
    m->imprimirMapa();

    int posX=0, posY=0;
    int posI=0, posJ=0;

    sf::RenderWindow window(sf::VideoMode(672-28,672-28), "League of Gems");
    window.setPosition(sf::Vector2i(0,0));

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(28,28));
    rect.setPosition(sf::Vector2f(posX,posY));
    rect.setFillColor(sf::Color::Green);

    sf::Texture gem;
    gem.loadFromFile("/home/mariano/CLionProjects/Proyecto2/Images/Gem/gem.png");

    sf::Sprite Sgem(gem);
    Sgem.setPosition(20*28, 0);



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

                        if((posX+28)==28*23){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if((m->getDato((posY/28),(posX/28)+1))==1) {
                            std::cout << "Obstacule" << std::endl;
                        }else
                        {
                            std::cout << m->getDato(posY,(posX/28)+1)<< std::endl;
                            std::cout << posY/28 <<" "<< posX/28 << std::endl;
                            rect.setPosition(sf::Vector2f(posX+=28, posY));
                        }

                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        if((posX-28)<0){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(m->getDato((posY/28),((posX/28)-1))==1){
                            std::cout << "Obstacule" << std::endl;
                        }else{
                            std::cout << m->getDato(posY,(posX/28)+1)<< std::endl;
                            std::cout << posY/28 <<" "<< posX/28 << std::endl;
                            rect.setPosition(sf::Vector2f(posX-=28, posY));
                        }
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        if((posY+28)==28*23){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(m->getDato(((posY/28)+1),(posX/28))==1){
                            std::cout << "Obstacule" << std::endl;
                        }else{
                            std::cout << m->getDato((posX/28),((posY/28)-1))<< std::endl;
                            std::cout << posY <<" "<< posX << std::endl;
                            rect.setPosition(sf::Vector2f(posX, posY+=28));
                        }
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        if((posY-28)<0){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(m->getDato(((posY/28)-1),(posX/28))==1){
                            std::cout << "Obstacule" << std::endl;
                        }else{
                            std::cout << m->getDato(posY,(posX/28)-1)<< std::endl;
                            std::cout << posY <<" "<< posX << std::endl;
                            rect.setPosition(sf::Vector2f(posX, posY-=28));
                        }
                    }
            }

        }

        window.clear();
        for (int i = 0; i<23;i ++){
            for (int j = 0; j<23; j++){
                if (m->getDato(j,i)==0){
                    sf::Texture texture;
                    texture.loadFromFile("../Images/Road/road.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(i*28, j*28);
                    window.draw(sprite);
                }
                else if(m->getDato(j,i)==1){
                    sf::Texture texture;
                    texture.loadFromFile("../Images/Bush/1.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(i*28, j*28);
                    window.draw(sprite);
                }
            }
        }


        window.draw(Sgem);
        window.draw(rect);
        window.display();
    }

}

void Ruta(){


}


