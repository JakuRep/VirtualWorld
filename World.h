//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_WORLD_H
#define VIRTUALWORLD_WORLD_H
#include "PriorityQueue.h"
#include "Map.h"
#include "WorldExceptions.h"
#include <iostream>
#include <stdlib.h>
#include <queue>
class Organism;
class World {
private:
    Map *GameMap;
    PriorityQueue *GameQueue;
public:
    explicit World(int width = 20, int height = 20);
    ~World();
    int getHeight();
    int getWidth();
    int getSize();
    int getAge();
    Organism * getXY(int x, int y);
    bool moveOrganism(int oldX, int oldY, int newX, int newY);
    void addOrganism(int x, int y, Organism *orgPtr);
    void killOrganism(Organism * orgPtr);
    void makeTour();
    void display();
    bool isInBound(int x, int y);



};


#endif //VIRTUALWORLD_WORLD_H
