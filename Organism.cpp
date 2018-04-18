//
// Created by majaku on 15.04.18.
//
#include "Organism.h"
#include "World.h"
Organism::Organism(int x, int y, int priority, int age, int strenght, World * myWorld) {
    this->priority = priority;
    this->age = age;
    this->strenght = strenght;
    this->order = 0;
    this->x = x;
    this->y = y;
    this->MyWorld = myWorld;
}
int Organism::getPriority() {
    return priority;
}
int Organism::getAge() {
    return age;
}
int Organism::getOrder() {
    return order;
}
void Organism::setOrder(int order) {
    this->order = order;
}
int Organism::getX() {
    return this->x;
}
void Organism::setX(int x) {
    this->x = x;
}
int Organism::getY() {
    return this->y;
}
void Organism::setY(int y) {
    this->y = y;
}
bool Organism::findFreeSpace(int &x, int &y) {
    if(MyWorld->getXY(x,y) == nullptr) {
        throw findingFreeSpaceWithEmptyCoordinates();
    } else {
        int xTmp, yTmp, direction = rand() % 4;
        for (int i = 0; i < 4; i++) {
            switch (direction) {
                case UP:
                    xTmp = x;
                    yTmp = y + 1;
                    break;
                case DOWN:
                    xTmp = x;
                    yTmp = y - 1;
                    break;
                case LEFT:
                    xTmp = x - 1;
                    yTmp = y;
                    break;
                case RIGHT:
                    xTmp = x + 1;
                    yTmp = y;
                    break;
            }

            if (MyWorld->isInBound(xTmp,yTmp) && MyWorld->getXY(xTmp, yTmp) == nullptr) {
                x = xTmp;
                y = yTmp;
                return true;
            } else {
                direction++;
                direction %= 4;
            }
        }
        return false;
    }
}
World * Organism::getWorld() {
    return this->MyWorld;
}

int Organism::getStrenght() {
    return strenght;
}