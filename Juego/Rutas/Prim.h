#ifndef PROYECTO2_PRIM_H
#define PROYECTO2_PRIM_H


class Prim {
    // Number of vertices in the graph
    static const int V = 9;
    int minKey(int key[], bool mstSet[], int V);
    int printMST(int parent[], int n, int graph[V][V]);
    void primMST(int graph[V][V], int V);
public:
    Prim(int graph[V][V]);
};

#endif //PROYECTO2_PRIM_H
