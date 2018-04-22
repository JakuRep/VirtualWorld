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
#include "Animal.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Grass.h"
#include "Dandelion.h"
int main() {
    srand(time(NULL));

    int x=0, y=0;
    World Earth = World(30,30);

    for(int i = 0; i < 30; i++) {
        if(i%4 == 0)
            Earth.addOrganism(i, i*13%30, new Wolf(&Earth));
        else if(i%4 == 1)
            Earth.addOrganism(i, i*13%30, new Sheep(&Earth));
        else if(i%4 == 2)
            Earth.addOrganism(i, i*13%30, new Grass(&Earth));
        else
            Earth.addOrganism(i, i*13%30, new Dandelion(&Earth));
    }
    Earth.display();
    char wait;
    while(std::cin >> wait) {
      Earth.makeTour();
    }






    return 0;
}