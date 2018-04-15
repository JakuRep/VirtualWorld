#include <iostream>
#include "Map.h"
#include "PriorityQueue.h"
#include "time.h"
#include "Organism.h"
#include <stdlib.h>
#include "World.h"
int main() {

    PriorityQueue MyQueue = PriorityQueue();
    Map MyWorld = Map(20, 20);
    Organism * orgPtr = new Organism(1,1);
    MyQueue.addOrganism(orgPtr);
    MyWorld.addOrganism(1,1,orgPtr);
    MyQueue.display();
    MyWorld.display();
    World EARTH = World(20,20);
    EARTH.addOrganism(2,2,orgPtr);
    EARTH.display();

    return 0;
}