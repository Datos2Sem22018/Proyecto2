#include<iostream>
#include<math.h>
#include<float.h>
#include<vector>
#include<set>
using namespace std;

#ifndef PROYECTO2_DIJKSTRA2_H
#define PROYECTO2_DIJKSTRA2_H

#define num 5

class Dijkstra2 {
    void findmin(float dist[num][num],int& min_x,int& min_y);
    void findpath(pair<int,int> previous[num][num],float dist[num][num],int dest_x,int dest_y,int source_x,int source_y);


public:
    Dijkstra2();
    void dijkstra(int source_x,int source_y,int dest_x,int dest_y,int grid[num][num]);
};


#endif //PROYECTO2_DIJKSTRA2_H
