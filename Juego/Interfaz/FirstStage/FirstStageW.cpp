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
#include "../Win/Win.h"
#include "../SecondStage/SecondStage.h"

int c;

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

    sf::RenderWindow firstStage(sf::VideoMode(744,644), "League of Gems");
    firstStage.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width/2)-322,0));

    int mouseXpos;
    int mouseYpos;

    sf::RectangleShape power1;
    power1.setPosition(0,28*23);
    power1.setFillColor(sf::Color::Black);


    if (level == 1){
        std::cout<<"You have selected Easy Game"<<std::endl;
        c=7;

    }else if (level == 2){
        std::cout<<"You have selected Medium Game"<<std::endl;
        c=16;
        mapa1[0][14]=4;
        mapa1[1][15]=4;
        mapa1[2][16]=4;
        mapa1[3][17]=4;
        mapa1[4][18]=4;
        mapa1[5][19]=4;
        mapa1[6][20]=4;
        mapa1[7][21]=4;
        mapa1[8][22]=4;
    }else{
        std::cout<<"You have selected Hard Game"<<std::endl;
        c=27;
        mapa1[0][14]=4;
        mapa1[1][15]=4;
        mapa1[2][16]=4;
        mapa1[3][17]=4;
        mapa1[4][18]=4;
        mapa1[5][19]=4;
        mapa1[6][20]=4;
        mapa1[7][21]=4;
        mapa1[8][22]=4;

        mapa1[0][12]=4;
        mapa1[1][13]=4;
        mapa1[2][14]=4;
        mapa1[3][15]=4;
        mapa1[4][16]=4;
        mapa1[5][17]=4;
        mapa1[6][18]=4;
        mapa1[7][19]=4;
        mapa1[8][20]=4;
        mapa1[9][21]=4;
        mapa1[10][22]=4;

    }

    sf::Texture gem;
    gem.loadFromFile("../Images/Gem/gem.png");
    sf::Sprite Sgem(gem);
    Sgem.setPosition(20*28, 0);

    Aliado *a1 = new Aliado(0,22);
    int playerX = a1->getPlayerSprite().getPosition().x;
    int playerY = a1->getPlayerSprite().getPosition().y;



    while(firstStage.isOpen()){
        std::cout<<c<<std::endl;
        if(c==0 && playerX/28==21 && playerY/28==1){

            firstStage.close();
            SecondStage::secondtStage(level);
            break;


        }
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

                        //AStar* aStar = new AStar();
                        //aStar->Star(playerX, playerY, mouseXpos, mouseYpos, grid);
                        //movementList = aStar->lvA;

                        if(mapa1[mouseXpos][mouseYpos]==1){
                            std::cout<< "Can't move to: " <<mouseXpos <<", "<<mouseYpos<<std::endl;
                        }
                        else if(mapa1[mouseXpos][mouseYpos]==4) {
                            std::cout<< "Enemy on: " <<mouseXpos <<", "<<mouseYpos<<std::endl;
                            sf::Font font;
                            font.loadFromFile("../Fonts/evafangoria.ttf");
                            //Title
                            sf::Text textAttack;
                            textAttack.setFont(font);
                            textAttack.setString("League of Gems");
                            textAttack.setCharacterSize(50);
                            sf::Color color(sf:: Color::Black);
                            textAttack.setFillColor(color);
                            textAttack.setPosition(200,25);
                            firstStage.draw(textAttack);
                            firstStage.clear(sf::Color(168, 192, 32));
                            firstStage.display();
                        }
                        else{
                            std::cout<<"From this position: "<<playerX/28<<", "<<playerY/28<<" to: ";
                            std::cout<< mouseXpos <<", "<<mouseYpos<<std::endl;

                            LinkedList<sf::Vector2f> movementList;
                            movementList.add(sf::Vector2f(0,22));
                            movementList.add(sf::Vector2f(1,22));
                            movementList.add(sf::Vector2f(3,22));
                            movementList.add(sf::Vector2f(4,21));
                            movementList.add(sf::Vector2f(5,20));
                            movementList.add(sf::Vector2f(6,20));
                            movementList.add(sf::Vector2f(7,19));
                            movementList.add(sf::Vector2f(8,19));
                            movementList.add(sf::Vector2f(9,19));
                            movementList.add(sf::Vector2f(10,18));
                            movementList.add(sf::Vector2f(11,18));
                            movementList.add(sf::Vector2f(12,16));
                            movementList.add(sf::Vector2f(13,14));
                            movementList.add(sf::Vector2f(14,13));
                            movementList.add(sf::Vector2f(15,12));
                            movementList.add(sf::Vector2f(16,10));
                            movementList.add(sf::Vector2f(17,10));
                            movementList.add(sf::Vector2f(18,9));
                            movementList.add(sf::Vector2f(19,8));
                            movementList.add(sf::Vector2f(20,6));
                            movementList.add(sf::Vector2f(21,4));
                            movementList.add(sf::Vector2f(22,2));

                            for(int a=0; a<movementList.size;a++)
                            {
                                std::cout<<movementList.getNode(a)->data.x<<", "<<movementList.getNode(a)->data.y<<std::endl;
                                if(a1->getPlayerSprite().getPosition().x<movementList.getNode(a)->data.x){

                                        sf::sleep(sf::milliseconds(250));
                                        a1->getPlayerSprite().setPosition(movementList.getNode(a)->data.x*28,movementList.getNode(a)->data.y*28);
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
                                else{

                                        sf::sleep(sf::milliseconds(250));
                                        a1->getPlayerSprite().setPosition(movementList.getNode(a)->data.x*28,movementList.getNode(a)->data.y*28);
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
                                if(a1->getPlayerSprite().getPosition().y<movementList.getNode(a)->data.y){

                                        sf::sleep(sf::milliseconds(250));
                                        a1->getPlayerSprite().setPosition(movementList.getNode(a)->data.x*28,movementList.getNode(a)->data.y*28);
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
                                else{

                                        sf::sleep(sf::milliseconds(250));
                                        a1->getPlayerSprite().setPosition(movementList.getNode(a)->data.x*28,movementList.getNode(a)->data.y*28);
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
                        }
                    }
                    //Movimiento con las teclas
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        if((playerX+28)==23*28){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(mapa1[playerY/28][playerX/28+1]==1){
                            std::cout << "Obstacule" << std::endl;
                        }else if(mapa1[playerY/28][playerX/28+1]==4){
                            std::cout << "Attacking to the Right"<< std::endl;
                            mapa1[playerY/28][playerX/28+1]=0;
                            c-=1;
                        }else
                        {
                            a1->getPlayerSprite().setPosition(sf::Vector2f((playerX)+=28, playerY));
                        }

                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        if((playerX*28-28)<0){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(mapa1[playerY/28][playerX/28-1]==1){
                            std::cout << "Obstacule" << std::endl;
                        }else if(mapa1[playerY/28][playerX/28-1]==4){
                            std::cout << "Attacking to the Left"<< std::endl;
                            mapa1[playerY/28][playerX/28-1]=0;
                            c-=1;
                        }else{
                            a1->setPosition(sf::Vector2f(playerX-= 28, playerY));

                        }
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        if((playerX+28)==28*23){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(mapa1[(playerY/28)+1][playerX/28]==1){
                            std::cout << "Obstacule" << std::endl;
                        }else if(mapa1[(playerY/28)+1][(playerX/28)]==4){
                            std::cout << "Attacking to Down"<< std::endl;
                            mapa1[(playerY/28)+1][(playerX/28)]=0;
                            c-=1;
                        }else{
                            a1->setPosition(sf::Vector2f(playerX, playerY+=28));
                        }
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        if((playerY-28)<0){
                            std::cout<<"Out of Bounds"<<std::endl;
                        }
                        else if(mapa1[playerY/28-1][playerX/28]==1){
                            std::cout << "Obstacule" << std::endl;
                        }else if(mapa1[playerY/28-1][playerX/28]==4){
                            std::cout << "Attacking to Up"<< std::endl;
                            mapa1[playerY/28-1][playerX/28]=0;
                            c-=1;
                        }else{
                            a1->setPosition(sf::Vector2f(playerX, playerY-=28));
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


        firstStage.draw(power1);
        firstStage.draw(Sgem);
        firstStage.draw(a1->getPlayerSprite());
        firstStage.display();
        firstStage.clear(sf::Color(168, 192, 32));
    }
}



