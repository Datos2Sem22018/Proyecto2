//
// Created by mariano on 06/11/18.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "FirstStageW.h"
#include "../../Aliado/Aliado.h"

int mapa1 [23][23] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,6,6,6},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,6,6,6},
{0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,4,0,6,6,6},
{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,4,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,4,0,0},
{0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,4,0},
{0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,4},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{5,5,5,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
{5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

void FirstStageW::firstStage(int level) {

    sf::RenderWindow firstStage(sf::VideoMode(644,644), "League of Gems");
    firstStage.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width/2)-322,0));

    if (level == 1){
        std::cout<<"You are selected Easy Game"<<std::endl;
    }else if (level == 2){
        std::cout<<"You are selected Medium Game"<<std::endl;
    }else{
        std::cout<<"You are selected Hard Game"<<std::endl;
    }

    sf::Texture gem;
    gem.loadFromFile("../Images/Gem/gem.png");
    sf::Sprite Sgem(gem);
    Sgem.setPosition(20*28, 0);

    Aliado *a1 = new Aliado(0,28*22);


    while(firstStage.isOpen()){
        sf::Event event;
        while (firstStage.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    firstStage.close();
                    break;
            }
        }


        for (int j = 0; j<23;j ++){
            for (int i = 0; i<23; i++){
                if (mapa1[i][j]==4)
                {
                    sf::RectangleShape rectEnemy;
                    rectEnemy.setFillColor(sf::Color::Green);
                    rectEnemy.setSize(sf::Vector2f(28,28));
                    rectEnemy.setPosition(j*28, i*28);
                    firstStage.draw(rectEnemy);
                }
                else if(mapa1[i][j]==1)
                {
                    sf::Texture texture;
                    texture.loadFromFile("../Images/Bush/1.png");
                    sf::Sprite spriteBush(texture);
                    spriteBush.setPosition(j*28, i*28);
                    firstStage.draw(spriteBush);
                }
            }
        }




        firstStage.draw(Sgem);
        firstStage.draw(a1->getPlayerSprite());
        firstStage.display();
        firstStage.clear(sf::Color(168, 192, 32));
    }
}
