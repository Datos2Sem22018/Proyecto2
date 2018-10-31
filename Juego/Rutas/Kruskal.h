//
// Created by karla on 31/10/18.
//

#ifndef PROYECTO2_KRUSKAL_H
#define PROYECTO2_KRUSKAL_H

#define V 9

class Kruskal {
    int find(int i);
    void union1(int i, int j);
    void kruskalMST(int cost[][V]);

public:
    Kruskal(int cost[][V]);

};


#endif //PROYECTO2_KRUSKAL_H
