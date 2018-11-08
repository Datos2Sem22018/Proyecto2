//
// Created by mariano on 06/11/18.
//

#ifndef PROYECTO2_FIRSTSTAGEW_H
#define PROYECTO2_FIRSTSTAGEW_H


#include "../../LikedList/LinkedList.h"
#include <SFML/Graphics.hpp>

class FirstStageW {


public:

    static LinkedList<sf::Vector2f> lvA;
    static LinkedList<sf::Vector2f> lvD;

    static void firstStage(int level);


};


#endif //PROYECTO2_FIRSTSTAGEW_H
