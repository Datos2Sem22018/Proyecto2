#include<SFML/Graphics.hpp>
#include<iostream>
#include<float.h>
#include<vector>
#include "../LikedList/LinkedList.h"

using namespace std;

#ifndef PROYECTO2_ASTAR_H
#define PROYECTO2_ASTAR_H


#define num 23

class AStar {
    typedef pair<float,pair<int,int>> Ppair;
    vector<pair<int,int>> pathA;
    bool closedList[num][num];
    struct cell{
        int parent_x,parent_y;
        float f,g,h;
        cell() : f(FLT_MAX),g(FLT_MAX),h(FLT_MAX),parent_x(-1),parent_y(-1) {};
    };
    bool isDestination(int row,int col, int xDest, int yDest);
    float calculateHvalue(int row,int col,int xDest, int yDest);
    void tracePath(int xSource, int ySource,int xDest, int yDest,cell cellDetails[][num]);

public:
    LinkedList<sf::Vector2f> lvA;
    void Star(int xSource, int ySource, int xDest, int yDest, int grid[num][num]);
    void ListPos(int i, int j);
    AStar();
    LinkedList<sf::Vector2f> getList();
};
#endif //PROYECTO2_ASTAR_H

/**
int main(){
    //int grid[num][num];
    int grid[num][num] = {{0, 0, 0, 0, 1},
                          {0, 0, 0, 1, 1},
                          {0, 0, 1, 1, 0},
                          {0, 1, 1, 0, 0},
                          {1, 1, 0, 0, 0}};//map with obstacle
    AStar* a = new AStar();
    a->Star(4, 0, 0, 4, grid);

}**/


