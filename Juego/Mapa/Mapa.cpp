//
// Created by mariano on 28/10/18.
//

#include <iostream>
#include "Mapa.h"



void Mapa::hacerMapa() {
    for(int i = 0; i<24;i++){
        for(int j = 0; j<24; j++){
            this->mapa[i][j]=0;
        }
    }
    this->mapa[0][23]=this->BaseAliada;
    this->mapa[23][0]=this->BaseEnemiga;

}

void Mapa::imprimirMapa() {
    for (int x = 0; x<24;x++){
        for (int y = 0; y<24;y++) {
            std::cout << mapa[x][y];
        }
        std::cout<<std::endl;
    }

}

int Mapa::getDato(int i, int j){
    return this->mapa[i][j];
}
