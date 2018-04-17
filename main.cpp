#include <iostream>
#include "Map.h"
#include "PriorityQueue.h"
#include "time.h"
#include "Organism.h"
#include <stdlib.h>
#include "World.h"
#include "time.h"
#include <stdlib.h>
#include "Plant.h"
int main() {
    srand(time(NULL));

    int x=0, y=0;
    World Earth = World(20,20);
    Organism * orgPtr = new Plant(19, 19,2,5,&Earth);
    Organism * orgPtr1 = new Plant(0,0,3,1,&Earth);
    Organism * orgPtr2 = new Plant(0,1,7,7,&Earth);
    Earth.addOrganism(0,0,orgPtr);
    for(int i = 0; i < 10; i++) {
        Earth.makeTour();
    }



    return 0;
}