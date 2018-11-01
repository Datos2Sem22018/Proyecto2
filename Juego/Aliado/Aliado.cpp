//
// Created by mariano on 27/10/18.
//

#include "Aliado.h"

Aliado::Aliado() {
    this->ataque = 10;
    this->vida = 100;
    this->velocidad = 110;
}

void Aliado::morir() {

}
void Aliado::atacar() {

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
