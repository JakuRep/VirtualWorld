//
// Created by majaku on 15.04.18.
//

#include "World.h"
World::World(int width, int height) {
    GameMap = Map(width, height);
    GameQueue = PriorityQueue(width*height);
    this->tour = 0;
}

int World::getSize() {
    return GameQueue.getSize();
}
int World::getWidth() {
    return GameMap.getWidth();
}
int World::getHeight() {
    return GameMap.getWidth();
}
Organism * World::getXY(int x, int y) {
    return GameMap.getOrganism(x,y);
}

bool World::moveOrganism(int oldX, int oldY, int newX, int newY) {
    return GameMap.moveOrganism(oldX, oldY, newX, newY);
}

void World::addOrganism(int x, int y, Organism *orgPtr) {

    GameQueue.addOrganism(orgPtr);
    GameMap.addOrganism(x,y,orgPtr);
}

void World::killOrganism(int x, int y) {
    Organism * orgPtr = getXY(x,y);
    if(orgPtr == nullptr)
        throw noOrganismWithThisPriorityException();
    else {
        GameMap.killOrganism(x, y);
        GameQueue.killOrganism(orgPtr);
        delete orgPtr;
    }
}

void World::killOrganism(Organism *orgPtr) {
    int x = orgPtr->getX(), y = orgPtr->getY();

    if(getXY(x,y) == nullptr)
        throw noOrganismWithThisPriorityException();
    else {
        GameMap.killOrganism(x,y);
        GameQueue.killOrganism(orgPtr);
        delete orgPtr;
    }
}
void World::display() {
    GameQueue.display();
    std::cout << "\n";
    GameMap.display();
    std::cout << "\n\n\n\n";
}