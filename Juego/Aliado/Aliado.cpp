//
// Created by mariano on 27/10/18.
//

#include "Aliado.h"
#include "../Enemigo/Enemigo.h"

Aliado::Aliado(int posX, int posY) {
    this->attack = 10;
    this->health = 100;
    this->moveSpeed = 0.2;
    this->posX=posX;
    this->posY=posY;


    tSoldier.loadFromFile("../Images/Soldier/soldier1.PNG");
    playerSprite.setTexture(tSoldier);
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

const sf::Sprite &Aliado::getPlayerSprite() const {
    return playerSprite;
}


