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
#include "Fox.h"
#include "Antelope.h"
#include "Turtle.h"
#include "Human.h"
int main() {
    srand(time(NULL));

    int x=0, y=0;
    World Earth = World(12,12);

    for(int i = 0; i < 11; i++) {
        if(i%5 == 0)
            Earth.addOrganism(i, i*13%12, new Wolf(&Earth));
        else if(i%6 == 1)
            Earth.addOrganism(i, i*13%12, new Sheep(&Earth));
        else if(i%6 == 2)
            Earth.addOrganism(i, i*13%12, new Guarana(&Earth));
        else if(i%6 == 3)
            Earth.addOrganism(i, i*13%12, new Grass(&Earth));
        else if(i%6 == 4)
            Earth.addOrganism(i, i*13%12, new Turtle(&Earth));
        else
            Earth.addOrganism(i, i*13%12, new Antelope(&Earth));
    }

    Earth.addOrganism(11,11,new Human(&Earth));
    Earth.display();
    char wait;
    char i = 0;
    while(i < 10) {

      Earth.display();
      Earth.makeTour();
      i++;
    }






    return 0;
}