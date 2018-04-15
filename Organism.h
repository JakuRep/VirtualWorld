//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_ORGANISM_H
#define VIRTUALWORLD_ORGANISM_H
#include <iostream>
#include "OrganismExceptions.h"
#include <stdlib.h>
using namespace std;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
class World;
class Organism {
    int order;
    int priority;
    int age;
    int x;
    int y;
    World * MyWorld;

public:
    Organism(int x=0, int y = 0,int priority=0, int age=0, World * myWorld=nullptr);
    int getPriority();
    int getAge();
    int getOrder();
    void setOrder(int order);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    virtual void akcja() = 0;
    bool findFreeSpace(int &x, int &y);
    char drawYourself();
    World * getWorld();
};


#endif //VIRTUALWORLD_ORGANISM_H
