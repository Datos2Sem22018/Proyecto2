//
// Created by mariano on 27/10/18.
//

#ifndef PROYECTO2_ALIADO_H
#define PROYECTO2_ALIADO_H

#include <SFML/Graphics.hpp>
#include "../Enemigo/Enemigo.h"
#include "../Mapa/Mapa.h"

class Aliado {
private:
    int health;
    int attack;
    float moveSpeed;
    int posX;
    int posY;
    sf::Vector2i* moveVector;
    sf::Texture tSoldier;
    sf::Sprite playerSprite;

public:
    Aliado(int posX, int posY);
    void morir();
    void atacar(Mapa* mapa, Enemigo* enemigo);
    void caminar();
    int getVida();
    void setVida(int Vida);
    int getAtaque();
    void setAtaque(int Ataque);

    const sf::Sprite &getPlayerSprite() const;
};


#endif //PROYECTO2_ALIADO_H
