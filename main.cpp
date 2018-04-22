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
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskyiHodweed.h"
int main() {
    srand(time(NULL));

    int x=0, y=0;
    World Earth = World(30,30);

    for(int i = 0; i < 30; i++) {
        if(i%5 == 0)
            Earth.addOrganism(i, i*13%30, new Sheep(&Earth));
        else if(i%6 == 1)
            Earth.addOrganism(i, i*13%30, new SosnowskyiHodweed(&Earth));
        else if(i%6 == 2)
            Earth.addOrganism(i, i*13%30, new Wolf(&Earth));
        else if(i%6 == 3)
            Earth.addOrganism(i, i*13%30, new Grass(&Earth));
        else if(i%6 == 4)
            Earth.addOrganism(i, i*13%30, new Guarana(&Earth));
        else
            Earth.addOrganism(i, i*13%30, new Belladonna(&Earth));
    }
    Earth.display();
    char wait;
    while(std::cin >> wait) {
      Earth.makeTour();
    }






    return 0;
}