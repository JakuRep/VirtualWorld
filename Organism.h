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
    int strenght;
    int age;
    int x;
    int y;
    World * MyWorld;
public:

    Organism(World * myWorld=nullptr);
    int getStrenght();
    void setStrenght(int strenght);
    int getPriority();
    void setPriority(int priority);
    int getOrder();
    void setOrder(int order);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getAge();
    void setAge(int age);
    World * getWorld();
    bool findFreeSpace(int &x, int &y);
    void killOrganism(Organism * orgPtr);
    virtual bool collision(Organism * orgPtr)=0;
    virtual void action()=0;
    virtual char drawYourself()=0;
};
#endif //VIRTUALWORLD_ORGANISM_H
