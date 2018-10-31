#ifndef PROYECTO2_KRUSKAL_H
#define PROYECTO2_KRUSKAL_H


class Kruskal {
    static const int V = 9;
    int find(int i);
    void union1(int i, int j);
    void kruskalMST(int cost[][V]);

public:
    Kruskal(int cost[][V]);

};


#endif //PROYECTO2_KRUSKAL_H
