//
// Created by mariano on 27/10/18.
//

#ifndef PROYECTO2_ENEMIGO_H
#define PROYECTO2_ENEMIGO_H


class Enemigo {
private:
    int vida;
    int ataque;
    int posX;
    int posY;
    //El Sprite de la animacion.

public:
    Enemigo();
    void morir();
    void atacar();

    int getVida();
    void setVida(int vidaNueva);

    void getAtaque();
    void setAtaque();

};


#endif //PROYECTO2_ENEMIGO_H
