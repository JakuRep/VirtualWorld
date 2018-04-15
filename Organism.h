//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_ORGANISM_H
#define VIRTUALWORLD_ORGANISM_H
#include <iostream>
#include "World.h"
#include "OrganismExceptions.h"
#include <stdlib.h>
using namespace std;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
class Organism {
    int order;
    int priority;
    int age;
    int x;
    int y;
    World * MyWorld;

public:
    Organism(int priority, int age) {
        this->priority = priority;
        this->age = age;
        this->order = 0;
        this->x = 0;
        this->y = 0;
    }
    int getPriority() {
        return priority;
    }
    int getAge() {
        return age;
    }
    int getOrder() {
        return order;
    }
    void setOrder(int order) {
        this->order = order;
    }
    int getX() {
        return this->x;
    }
    void setX(int x) {
        this->x = x;
    }
    int getY() {
        return this->y;
    }
    void setY(int y) {
        this->y = y;
    }
    void akcja() {

    }
    bool findFreeSpace(int x, int y) {
        if(MyWorld->getXY(x,y) == nullptr) {
            throw findingFreeSpaceWithEmptyCoordinates();
        } else {
            int xTmp, yTmp, direction = rand() % 4;
            switch (direction) {
                case UP:
                    xTmp = x;
                    yTmp = y+1;
                    break;
                case DOWN:
                    xTmp = x;
                    yTmp = y-1;
                    break;
                case LEFT:
                    xTmp = x-1;
                    yTmp = y;
                    break;
                case RIGHT:
                    xTmp = x+1;
                    yTmp = y;
                    break;
            }
        }
    }
};


#endif //VIRTUALWORLD_ORGANISM_H
