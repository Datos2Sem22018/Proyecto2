//
// Created by mariano on 27/10/18.
//

#ifndef PROYECTO2_ALIADO_H
#define PROYECTO2_ALIADO_H


class Aliado {
private:
    int vida;
    int ataque;
    int velocidad;
    // el Sprite Animation
public:
    void morir();
    void atacar();
    void caminar();
    void getVida();
    void setVida();
    void getAtaque();
    void setAtaque();
};


#endif //PROYECTO2_ALIADO_H
