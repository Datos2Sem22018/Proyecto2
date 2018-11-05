#include "BreadthFirstSearch.h"

bool BreadthFirstSearch::BFS(int (*graph)[V], int s, int dest, int v) {
    int pred[v];
    int dist[v];
    std::list<int> queue;
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[s] = true;
    dist[s] = 0;
    queue.push_back(s);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < V; ++i) {
            if (!visited[graph[u][i]]) {
                visited[graph[u][i]] = true;
                dist[graph[u][i]] = dist[u] + 1;
                pred[graph[u][i]] = u;
                queue.push_back(graph[u][i]);
                if (graph[u][i] == dest) {
                    return true;
                }
            }
        }
    }
    return false;
}

void BreadthFirstSearch::printShortestDistance(int(*graph)[V], int s, int dest, int v) {
    int pred[v], dist[v];
    if (!BFS(graph, s, dest, v)) {
        std::cout << "Given source and destination" << " are not connected" << std::endl;
        return;
    }
    std::vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    std::cout << "Shortest path length is: " << dist[dest];
    std::cout << "\nPath is::\n";
    for (int i = V-1; i >= 0; i--) {
        std::cout << path[i] << " ";
    }
}