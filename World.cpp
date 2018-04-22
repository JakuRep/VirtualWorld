//
// Created by majaku on 15.04.18.
//

#include "World.h"
#include "Organism.h"
World::World(int width, int height) {
    GameMap =new Map(width, height);
    GameQueue =new PriorityQueue(width*height);
}
World::~World() {
    delete GameMap;
    delete GameQueue;
}
int World::getSize() {
    return GameQueue->getSize();
}
int World::getWidth() {
    return GameMap->getWidth();
}
int World::getHeight() {
    return GameMap->getWidth();
}
int World::getAge() {
    return this->GameQueue->getTour();
}
Organism * World::getXY(int x, int y) {
    return (GameMap->getOrganism(x,y));
}
bool World::moveOrganism(int oldX, int oldY, int newX, int newY) {
    return GameMap->moveOrganism(oldX, oldY, newX, newY);
}
void World::addOrganism(int x, int y, Organism *orgPtr) {
    GameMap->addOrganism(x,y,orgPtr);
    GameQueue->addOrganism(orgPtr);
}
void World::killOrganism(Organism *orgPtr) {
    GameQueue->killOrganism(orgPtr);
    GameMap->killOrganism(orgPtr);
}
void World::makeTour() {
    GameQueue->makeTour();
    GameQueue->cleanDeadBodies();
    display();
}
void World::display() {
    system("clear");
    GameQueue->display();
    //std::cout << "\n";

    GameMap->display();
    //std::cout << "\n\n";
}
bool World::isInBound(int x, int y) {
    return GameMap->isInMap(x,y);
}


