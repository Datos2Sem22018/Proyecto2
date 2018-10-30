//
// Created by mariano on 28/10/18.
//

#include <iostream>
#include "Mapa.h"



void Mapa::hacerMapa() {
    for(int i = 0; i<23;i++){
        for(int j = 0; j<23; j++){
            this->mapa[i][j]=0;
        }
    }
    this->mapa[0][22]=this->BaseAliada;
    this->mapa[22][0]=this->BaseEnemiga;
    this->mapa[22][22]=this->camino;

}

void Mapa::imprimirMapa() {
    for (int x = 0; x<23;x++){
        for (int y = 0; y<23;y++) {
            std::cout << mapa[x][y];
        }
        std::cout<<std::endl;
    }

}

int Mapa::getDato(int i, int j){
    return this->mapa[i][j];
}
