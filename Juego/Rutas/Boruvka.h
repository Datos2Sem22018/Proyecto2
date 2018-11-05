
#ifndef BORUVKA_BORUVKA_H
#define BORUVKA_BORUVKA_H
#define V 9

class Boruvka {
    struct Edge
    {
        int src, dest, weight;
    };
public:
    struct Graph
    {
        int Vert;
        int E;
        Edge* edge;
    };
    Boruvka(int cost[][V], struct Graph* graph);
    static struct Boruvka::Graph* createGraph(int Vi, int E);



private:

    struct subset
    {
        int parent;
        int rank;
    };
    void boruvkaMST(struct Graph* graph);

    int find(struct subset subsets[], int i);
    void Union(struct subset subsets[], int x, int y);
    void designValue(int cost[][V],Boruvka::Graph* graph);
};
/**
int main(){

    int Vi = V;  // Number of vertices in graph
    int E = 30;  // Number of edges in graph
    int cost[][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                     {4, 0, 8, 0, 0, 0, 0, 11, 0},
                     {0, 8, 0, 7, 0, 4, 0, 0, 2},
                     {0, 0, 7, 0, 9, 14, 0, 0, 0},
                     {0, 0, 0, 9, 0, 10, 0, 0, 0},
                     {0, 0, 4, 14, 10, 0, 2, 0, 0},
                     {0, 0, 0, 0, 0, 2, 0, 1, 6},
                     {8, 11, 0, 0, 0, 0, 1, 0, 7},
                     {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    struct Boruvka::Graph *graph = Boruvka::createGraph(Vi, E);
    Boruvka* bor = new Boruvka(cost, graph);

    return 0;
}
 **/

#endif //BORUVKA_BORUVKA_H

