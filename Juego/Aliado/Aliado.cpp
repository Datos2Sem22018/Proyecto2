//
// Created by mariano on 27/10/18.
//

#include "Aliado.h"
#include "../Enemigo/Enemigo.h"

Aliado::Aliado() {
    this->ataque = 10;
    this->vida = 100;
    this->velocidad = 110;
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

void Aliado::caminar() {

}
int Aliado::getVida() {
    return vida;
}

void Aliado::setVida(int Vida) {
    this->vida = Vida;
}
int Aliado::getAtaque() {
    return ataque;
}
void Aliado::setAtaque(int Ataque) {
    this->ataque = Ataque;
}
