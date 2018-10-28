//
// Created by mariano on 27/10/18.
//

#ifndef PROYECTO2_RUTAS_H
#define PROYECTO2_RUTAS_H


class Rutas {

private:
    int matriz;

public:
    int Dijkstra(int matriz);
    int Prim(int matriz);
    int Kruskal(int matriz);
    int Pathfinding(int matriz);
    int algoritmoBase(int matriz);

    int getMatriz() const;
    void setMatriz(int matriz);


};


#endif //PROYECTO2_RUTAS_H
