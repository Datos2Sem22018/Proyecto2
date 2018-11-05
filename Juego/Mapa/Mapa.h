//
// Created by mariano on 28/10/18.
//

#ifndef PROYECTO2_MAPA_H
#define PROYECTO2_MAPA_H


class Mapa {
private:

    int noHayCamino = 0;
    int camino=1;
    int obstaculo = 2;
    int aliado = 3;
    int enemigo = 4;
    int BaseAliada = 5;
    int BaseEnemiga = 6;

public:
    int mapa [23][23];
    void hacerMapa();
    void imprimirMapa();
    int getDato(int, int);

};


#endif //PROYECTO2_MAPA_H
