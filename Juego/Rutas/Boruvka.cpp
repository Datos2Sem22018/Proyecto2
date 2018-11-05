#include <stdio.h>
#include <bits/stdc++.h>
#include "Boruvka.h"
#define V 9


Boruvka::Boruvka(int cost[][V], Boruvka::Graph *graph) {
    designValue(cost, graph);
    boruvkaMST(graph);
}
void Boruvka::boruvkaMST(struct Graph* graph)
{
    int Vi = graph->Vert, E = graph->E;
    Edge *edge = graph->edge;

    struct subset *subsets = new subset[V];

    int *cheapest = new int[V];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        cheapest[v] = -1;
    }

    int numTrees = V;
    int MSTweight = 0;

    while (numTrees > 1)
    {
        for (int v = 0; v < V; ++v)
        {
            cheapest[v] = -1;
        }
        for (int i=0; i<E; i++)
        {
            int set1 = find(subsets, edge[i].src);
            int set2 = find(subsets, edge[i].dest);

            if (set1 == set2)
                continue;

            else
            {
                if (cheapest[set1] == -1 ||
                    edge[cheapest[set1]].weight > edge[i].weight)
                    cheapest[set1] = i;

                if (cheapest[set2] == -1 ||
                    edge[cheapest[set2]].weight > edge[i].weight)
                    cheapest[set2] = i;
            }
        }
        for (int i=0; i<V; i++)
        {
            if (cheapest[i] != -1)
            {
                int set1 = find(subsets, edge[cheapest[i]].src);
                int set2 = find(subsets, edge[cheapest[i]].dest);

                if (set1 == set2)
                    continue;
                MSTweight += edge[cheapest[i]].weight;
                printf("Edge %d-%d\n",
                       edge[cheapest[i]].src, edge[cheapest[i]].dest);

                Union(subsets, set1, set2);
                numTrees--;
            }
        }
    }

    printf("Weight of MST is %d\n", MSTweight);
    return;
}

Boruvka::Graph *Boruvka::createGraph(int Vi, int E) {
    Graph* graph = new Graph;
    graph->Vert = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int Boruvka::find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent =
                find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
void Boruvka::Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void Boruvka::designValue(int cost[][V],Boruvka::Graph* graph){
    int mincost = 0; // Cost of min MST.
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
        {
            if (cost[i][j] == 0) {
            }
            else{
                graph->edge[mincost].src = i;
                graph->edge[mincost].dest = j;
                graph->edge[mincost].weight = cost[i][j];
                mincost++;
            }
        }
}
