//
// Created by mariano on 27/10/18.
//

#include "PrincipalW.h"
#include "../../Mapa/Mapa.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define sDown 0
#define sLeft 0
#define sRight 0
#define sUp 0

void PrincipalW::principalW() {


    Mapa *m = new Mapa();

    Dijkstra* dijkstra = new Dijkstra();

    int posX=0, posY=0;

    enum Directions {Down, Left, Right, Up};

    sf::Vector2i source(1, Down);

    int sourceX=28, sourceY=Down;


    sf::RenderWindow window(sf::VideoMode(644,644), "League of Gems");
    window.setPosition(sf::Vector2i(0,0));

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(28,28));
    rect.setPosition(sf::Vector2f(posX,posY));
    rect.setFillColor(sf::Color::Green);


    sf::Texture gem;
    gem.loadFromFile("../Images/Gem/gem.png");

    sf::Sprite Sgem(gem);
    Sgem.setPosition(20*28, 0);

    sf::Texture tSoldier;
    tSoldier.loadFromFile("../Images/Soldier/soldier1.PNG");
    sf::Sprite playerSprite;
    playerSprite.setTexture(tSoldier);

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

                        if (dijkstra->dijkstra(m->mapa, (rect.getPosition().x) / 28)) {
                            while ((posX/28) != ((sf::Mouse::getPosition().x)/28)){
                                while((posY/28) != ((sf::Mouse::getPosition().y)/28)){
                                    rect.setPosition(posX, posY+=28);
                                }
                                rect.setPosition(posX+=28, posY);
                            }

                        } else {
                            std::cout << "No path" << std::endl;
                        }
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

                            source.y = Right;
                            playerSprite.setPosition(sf::Vector2f(posX+=28, posY));
                        }

                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        if((posX-28)<0){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(m->getDato((posY/28),((posX/28)-1))==1){
                            std::cout << "Obstacule" << std::endl;
                        }else{
                            source.y = Left;
                            playerSprite.setPosition(sf::Vector2f(posX-=28, posY));
                        }
                    }

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        if((posY+28)==28*23){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(m->getDato(((posY/28)+1),(posX/28))==1){
                            std::cout << "Obstacule" << std::endl;
                        }else{
                            source.y = Down;
                            playerSprite.setPosition(sf::Vector2f(posX, posY+=28));
                        }
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        if((posY-28)<0){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(m->getDato(((posY/28)-1),(posX/28))==1){
                            std::cout << "Obstacule" << std::endl;
                        }else{
                            source.y = Up;
                            playerSprite.setPosition(sf::Vector2f(posX, posY-=28));
                        }
                    }
            }

        }


        for (int i = 0; i<23;i ++){
            for (int j = 0; j<23; j++){
                if (m->getDato(j,i)==0){

                }
                else if(m->getDato(j,i)==1){
                    sf::Texture texture;
                    texture.loadFromFile("../Images/Bush/1.png");
                    sf::Sprite spriteBush(texture);
                    spriteBush.setPosition(i*28, j*28);
                    window.draw(spriteBush);
                }
            }
        }

        source.x++;
        if(source.x*28>= tSoldier.getSize().x){
            source.x=0;
        }

        window.draw(Sgem);
        playerSprite.setTextureRect(sf::IntRect(source.x*28, source.y*28,28,28));
        window.draw(playerSprite);
        window.display();
        window.clear(sf::Color(168, 192, 32));
    }

}

void Ruta(){


}


