//
// Created by mariano on 28/10/18.
//

#include <iostream>
#include "Mapa.h"

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
