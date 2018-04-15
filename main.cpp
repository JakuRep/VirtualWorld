#include <iostream>
#include "Map.h"
#include "PriorityQueue.h"
#include "time.h"
#include "Organism.h"
#include <stdlib.h>
#include "World.h"
#include "time.h"
#include <stdlib.h>
int main() {
    srand(time(NULL));
    int x=0, y=0;
    World Earth = World(20,20);
    Organism * orgPtr = new Organism(1,1,&Earth);
    Organism * orgPtr1 = new Organism(1,1,&Earth);
    Organism * orgPtr2 = new Organism(1,1,&Earth);
    Organism * orgPtr3 = new Organism(1,1,&Earth);
    Earth.addOrganism(1,0, orgPtr);
    Earth.addOrganism(0,0, orgPtr1);
    Earth.addOrganism(0,1, orgPtr2);
    Earth.makeTour();


    return 0;
}