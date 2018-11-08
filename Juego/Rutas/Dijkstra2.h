#include<SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include<float.h>
#include<vector>
#include<set>
#include "../LikedList/LinkedList.h"

using namespace std;

#ifndef PROYECTO2_DIJKSTRA2_H
#define PROYECTO2_DIJKSTRA2_H

#define num 23

class Dijkstra2 {
    void findmin(float dist[num][num],int& min_x,int& min_y);
    void findpath(pair<int,int> previous[num][num],float dist[num][num],int dest_x,int dest_y,int source_x,int source_y);


public:
    static LinkedList<sf::Vector2f> lvD;
    Dijkstra2();
    void dijkstra(int source_x,int source_y,int dest_x,int dest_y,int grid[num][num]);
};


#endif //PROYECTO2_DIJKSTRA2_H

/**
#include <iostream>
#include "Dijkstra2.h"
#define num 5
int main(){
    //int grid[num][num];
    int grid[num][num] = {{0, 1, 0, 0, 1},
                          {1, 1, 0, 1, 1},
                          {1, 0, 1, 1, 0},
                          {1, 1, 1, 0, 0},
                          {1, 1, 0, 0, 0}};
    Dijkstra2* a = new Dijkstra2();
    a->dijkstra(4, 0, 0, 1, grid);
}**/