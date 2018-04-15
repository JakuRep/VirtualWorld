//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_WORLD_H
#define VIRTUALWORLD_WORLD_H
#include "PriorityQueue.h"
#include "Map.h"
#include "WorldExceptions.h"
#include <iostream>
class Organism;
class World {
private:
    Map *GameMap;
    PriorityQueue *GameQueue;
    int tour;
public:
    explicit World(int width = 20, int height = 20);
    ~World();
    int getHeight();
    int getWidth();
    int getSize();
    Organism * getXY(int x, int y);
    bool moveOrganism(int oldX, int oldY, int newX, int newY);
    void killOrganism(int x, int y);
    void killOrganism(Organism * orgPtr);
    void addOrganism(int x, int y, Organism *orgPtr);
    void display();
    void makeTour();


};
#include "Organism.h"

#endif //VIRTUALWORLD_WORLD_H
