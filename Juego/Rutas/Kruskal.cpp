#include <bits/stdc++.h>
using namespace std;
#include "Kruskal.h"
#define V 9
int parent[V];

Kruskal::Kruskal(int (*cost)[V]) {
    kruskalMST(cost);
}

int Kruskal::find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void Kruskal::union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void Kruskal::kruskalMST(int cost[][V])
{
    int mincost = 0; // Cost of min MST.
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n Minimum cost= %d \n", mincost);
}
