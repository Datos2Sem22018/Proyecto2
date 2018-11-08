//
// Created by mariano on 27/10/18.
//

#include "Aliado.h"
#include "../Enemigo/Enemigo.h"
#include <unistd.h>

Aliado::Aliado(int posX, int posY) {
    this->attack = 10;
    this->health = 100;
    this->moveSpeed = 0.2;
    this->posX=posX;
    this->posY=posY;


    tSoldier.loadFromFile("../Images/Soldier/soldier2.PNG");
    playerSprite.setTexture(tSoldier);
    playerSprite.setPosition(posX*28,posY*28);
}

void Aliado::morir() {


}
void Aliado::atacar(Mapa *mapa, Enemigo *enemigo) {
    if(((mapa->getDato((this->posY/28),(this->posX/28)+1))==4)||
    (mapa->getDato((this->posY/28),((this->posX/28)-1))==4)||
    (mapa->getDato(((this->posY/28)+1),(this->posX/28))==4)||
    (mapa->getDato(((this->posY/28)-1),(this->posX/28))==4)){
        enemigo->setVida(enemigo->getVida()-1);

    }
}

sf::Sprite &Aliado::getPlayerSprite() {
    return playerSprite;
}

void Aliado::setPosition(sf::Vector2f pos) {
    this->playerSprite.setPosition(pos);

}

int Aliado::getXpos() {
    return this->posX;
}

int Aliado::getYpos() {
    return this->posY;
}

void Aliado::setXpos(int offset) {
    this->posX=offset;

}

void Aliado::setYpos(int offset) {
    this->posY=offset;

}

void Aliado::move(int mouseXpos, int mouseYpos){




}


