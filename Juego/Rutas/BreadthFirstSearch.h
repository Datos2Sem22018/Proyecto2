#ifndef PROYECTO2_BREADTHFIRSTSEARCH_H
#define PROYECTO2_BREADTHFIRSTSEARCH_H
#include <list>
#include <climits>
#include <iostream>
#include <vector>


class BreadthFirstSearch {
private:
    static const int V = 23;
    void printShortestDistance(int graph[V][V], int s, int dest, int v);
public:
    BreadthFirstSearch() = default;
    bool BFS(int graph[V][V], int s, int dest, int v);
};


#endif //PROYECTO2_BREADTHFIRSTSEARCH_H
