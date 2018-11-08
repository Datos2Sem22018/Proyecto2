//
// Created by mariano on 06/11/18.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <unistd.h>
#include "FirstStageW.h"
#include "../../Aliado/Aliado.h"
#include "../../LikedList/LinkedList.h"
#include "../../Rutas/AStar.h"


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
int grid[23][23];


void FirstStageW::firstStage(int level) {

    sf::RenderWindow firstStage(sf::VideoMode(644,644), "League of Gems");
    firstStage.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width/2)-322,0));

    int mouseXpos;
    int mouseYpos;

    if (level == 1){
        std::cout<<"You have selected Easy Game"<<std::endl;
    }else if (level == 2){
        std::cout<<"You have selected Medium Game"<<std::endl;
    }else{
        std::cout<<"You have selected Hard Game"<<std::endl;
    }

    sf::Texture gem;
    gem.loadFromFile("../Images/Gem/gem.png");
    sf::Sprite Sgem(gem);
    Sgem.setPosition(20*28, 0);

    Aliado *a1 = new Aliado(0,22);



    while(firstStage.isOpen()){
        sf::Event event;
        while (firstStage.pollEvent(event)){
            switch (event.type)
            {
                case sf::Event::Closed:
                    firstStage.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        mouseXpos=(sf::Mouse::getPosition(firstStage).x)/28;
                        mouseYpos=(sf::Mouse::getPosition(firstStage).y)/28;

                        for(int i = 0; i < 23; i ++){
                            for(int j = 0; j < 23; j ++){
                                if(mapa1[i][j] == 0){
                                    grid[i][j] = 1;
                                }else{
                                    grid[i][j] = 0;
                                }
                            }
                        }
                        int playerX = a1->getPlayerSprite().getPosition().x;
                        int playerY = a1->getPlayerSprite().getPosition().y;
                        AStar* aStar = new AStar();
                        aStar->Star(playerX, playerY, mouseXpos, mouseYpos, grid);

                        if(mapa1[mouseXpos][mouseYpos]==1){
                            std::cout<< "Can't move to: " <<mouseXpos <<", "<<mouseYpos<<std::endl;
                        }else{
                            std::cout<<"From this position: "<<a1->getPlayerSprite().getPosition().x<<", "<<a1->getPlayerSprite().getPosition().y<<" to: ";
                            std::cout<< mouseXpos <<", "<<mouseYpos<<std::endl;



                            for(int a=0; a<AStar::lvA->size;a++)
                            {

                                if(a1->getPlayerSprite().getPosition().x<AStar::lvA->getNode(a)->data.x){
                                    for(int a=0; a<28;a++){
                                        sf::sleep(sf::milliseconds(5));
                                        a1->getPlayerSprite().move(1.0f,0.0f);
                                        for (int j = 0; j<23;j ++){
                                            for (int i = 0; i<23; i++){
                                                if (mapa1[i][j]==4)
                                                {
                                                    sf::Texture texture;
                                                    texture.loadFromFile("../Images/zombie/z1.png");
                                                    sf::Sprite spriteEnemy(texture);
                                                    spriteEnemy.setPosition(j*28, i*28);
                                                    firstStage.draw(spriteEnemy);
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
                                if(a1->getPlayerSprite().getPosition().x>AStar::lvA->getNode(a)->data.x){
                                    for(int a=0; a<28;a++){
                                        sf::sleep(sf::milliseconds(5));
                                        a1->getPlayerSprite().move(-1.0f,0.0f);
                                        for (int j = 0; j<23;j ++){
                                            for (int i = 0; i<23; i++){
                                                if (mapa1[i][j]==4)
                                                {
                                                    sf::Texture texture;
                                                    texture.loadFromFile("../Images/zombie/z1.png");
                                                    sf::Sprite spriteEnemy(texture);
                                                    spriteEnemy.setPosition(j*28, i*28);
                                                    firstStage.draw(spriteEnemy);
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
                                if(a1->getPlayerSprite().getPosition().y<AStar::lvA->getNode(a)->data.y){
                                    for(int a=0; a<28;a++){
                                        sf::sleep(sf::milliseconds(5));
                                        a1->getPlayerSprite().move(0.0f,1.0f);
                                        for (int j = 0; j<23;j ++){
                                            for (int i = 0; i<23; i++){
                                                if (mapa1[i][j]==4)
                                                {
                                                    sf::Texture texture;
                                                    texture.loadFromFile("../Images/zombie/z1.png");
                                                    sf::Sprite spriteEnemy(texture);
                                                    spriteEnemy.setPosition(j*28, i*28);
                                                    firstStage.draw(spriteEnemy);
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
                                if(a1->getPlayerSprite().getPosition().x>AStar::lvA->getNode(a)->data.x){
                                    for(int a=0; a<28;a++){
                                        sf::sleep(sf::milliseconds(5));
                                        a1->getPlayerSprite().move(0.0f,-1.0f);
                                        for (int j = 0; j<23;j ++){
                                            for (int i = 0; i<23; i++){
                                                if (mapa1[i][j]==4)
                                                {
                                                    sf::Texture texture;
                                                    texture.loadFromFile("../Images/zombie/z1.png");
                                                    sf::Sprite spriteEnemy(texture);
                                                    spriteEnemy.setPosition(j*28, i*28);
                                                    firstStage.draw(spriteEnemy);
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


                                /**
                                a1->getPlayerSprite().setPosition(positions[a]);
                                firstStage.clear(sf::Color(168, 192, 32));
                                firstStage.draw(a1->getPlayerSprite());
                                firstStage.display();
                                 **/
                            }








                        }


                    }
            }
        }
        for (int j = 0; j<23;j ++){
            for (int i = 0; i<23; i++){
                if (mapa1[i][j]==4)
                {
                    sf::Texture texture;
                    texture.loadFromFile("../Images/zombie/z1.png");
                    sf::Sprite spriteEnemy(texture);
                    spriteEnemy.setPosition(j*28, i*28);
                    firstStage.draw(spriteEnemy);
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


