//
// Created by zuckerberg on 04/11/18.
//

#ifndef PROYECTO2_DIJKSTRA_H
#define PROYECTO2_DIJKSTRA_H
#include <climits>
#include <cstdio>


class Dijkstra {
private:
    static const int V = 23;
    int minDistance(int dist[], bool sptSet[]);
    int printSolution(int dist[], int n);
public:
    Dijkstra() = default;
    bool dijkstra(int graph[V][V], int src);
};


#endif //PROYECTO2_DIJKSTRA_H
