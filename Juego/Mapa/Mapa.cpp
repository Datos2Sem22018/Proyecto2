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
    this->mapa[0][21]=this->BaseAliada;
    this->mapa[0][20]=this->BaseAliada;
    this->mapa[1][22]=this->BaseAliada;
    this->mapa[1][21]=this->BaseAliada;
    this->mapa[1][20]=this->BaseAliada;
    this->mapa[2][22]=this->BaseAliada;
    this->mapa[2][21]=this->BaseAliada;
    this->mapa[2][20]=this->BaseAliada;

    //Set la base enemiga
    this->mapa[22][0]=this->BaseEnemiga;
    this->mapa[21][0]=this->BaseEnemiga;
    this->mapa[20][0]=this->BaseEnemiga;
    this->mapa[22][1]=this->BaseEnemiga;
    this->mapa[21][1]=this->BaseEnemiga;
    this->mapa[20][1]=this->BaseEnemiga;
    this->mapa[22][2]=this->BaseEnemiga;
    this->mapa[21][2]=this->BaseEnemiga;
    this->mapa[20][2]=this->BaseEnemiga;



    this->mapa[22][22]=this->camino;
    srand(time(0));
    for (int i=0; i<30;i++){

        int x =rand()%22;
        int y =rand()%22;
        std::cout<<x<<","<<y<<std::endl;
        this->mapa[x][y]=this->obstaculo;
    }

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
