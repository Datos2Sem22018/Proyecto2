//
// Created by mariano on 27/10/18.
//

#ifndef PROYECTO2_ENEMIGO_H
#define PROYECTO2_ENEMIGO_H


class Enemigo {
private:
    int vida;
    int ataque;
    int velocidad;

public:
    void morir();
    void atacar();
    void caminar();


    void getVida();
    void setVida();

    void getAtaque();
    void setAtaque();




};


#endif //PROYECTO2_ENEMIGO_H
