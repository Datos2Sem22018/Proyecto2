#include "Dijkstra.h"

Dijkstra::Dijkstra(int graph[V][V]){

}

int Dijkstra::minDistance(int *dist, bool *sptSet) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; ++i) {
        if (!sptSet[i] && dist[i] <= min) {
            min = dist[i], min_index = i;
        }
    }
    return min_index;
}

int Dijkstra::printSolution(int *dist, int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

bool Dijkstra::dijkstra(int graph[V][V], int src){
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    dist[src] = 0;
    for (int j = 0; j < V-1; ++j) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int i = 0; i < V; ++i) {
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u]+graph[u][i] < dist[i]) {
                dist[i] = dist[u] + graph[u][i];
            } else {
                return true;
            }
        }
    }
    return false;
}