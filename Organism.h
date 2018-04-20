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

    virtual bool collision(Organism * orgPtr)=0;
    virtual void action()=0;
    virtual char drawYourself()=0;
    //getters setters
    int getStrenght();
    int getPriority();
    void setPriority(int priority);
    void setStrenght(int strenght);
    int getAge();
    int getOrder();
    void setOrder(int order);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    World * getWorld();


    bool findFreeSpace(int &x, int &y);



};


#endif //VIRTUALWORLD_ORGANISM_H
