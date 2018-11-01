//
// Created by mariano on 27/10/18.
//

#ifndef PROYECTO2_ALIADO_H
#define PROYECTO2_ALIADO_H

#include <SFML/Graphics.hpp>


class Aliado {
private:
    int vida;
    int ataque;
    int velocidad;
    sf::Vector2i* moveVector;
    // el Sprite Animation
public:
    Aliado();
    void morir();
    void atacar();
    void caminar();
    int getVida();
    void setVida(int Vida);
    int getAtaque();
    void setAtaque(int Ataque);
};


#endif //PROYECTO2_ALIADO_H
