#include <iostream>
#include "Map.h"
#include "PriorityQueue.h"
#include "time.h"
#include "Organism.h"
#include <stdlib.h>
#include "World.h"
int main() {

    World Earth = World(20,20);
    Organism * orgPtr = new Organism(1,1);
    Earth.addOrganism(0,0, orgPtr);
    Earth.makeTour();

    return 0;
}