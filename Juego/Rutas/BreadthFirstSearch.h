#ifndef PROYECTO2_BREADTHFIRSTSEARCH_H
#define PROYECTO2_BREADTHFIRSTSEARCH_H
#include <list>
#include <climits>
#include <iostream>
#include <vector>


class BreadthFirstSearch {
private:
    static const int V = 23;
    bool BFS(int graph[V][V], int s, int dest, int v);
public:
    BreadthFirstSearch() = default;
    std::vector<int> returnShortestDistance(int graph[V][V], int s, int dest, int v);
};


#endif //PROYECTO2_BREADTHFIRSTSEARCH_H
