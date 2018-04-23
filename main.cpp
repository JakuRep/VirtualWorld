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
    World Earth = World(30,30);
    Organism * MaciejJakubowski = new Human(&Earth);
    for(int i = 0; i < 30; i++) {
        if(i%5 == 0)
            Earth.addOrganism(i, i*13%30, new Wolf(&Earth));
        else if(i%10 == 1)
            Earth.addOrganism(i, i*13%30, new Sheep(&Earth));
        else if(i%10 == 2)
            Earth.addOrganism(i, i*13%30, new Sheep(&Earth));
        else if(i%10 == 3)
            Earth.addOrganism(i, i*13%30, new Wolf(&Earth));
        else if(i%10 == 4)
            Earth.addOrganism(i, i*13%30, new SosnowskyiHodweed(&Earth));
        else if(i%10 == 5)
            Earth.addOrganism(i, i*13%30, new SosnowskyiHodweed(&Earth));
        else if(i%10 == 6)
            Earth.addOrganism(i, i*13%30, new Antelope(&Earth));
        else if(i%10 == 7)
            Earth.addOrganism(i, i*13%30, new Sheep(&Earth));
        else if(i%10 == 8)
            Earth.addOrganism(i, i*13%30, new Antelope(&Earth));
    }

    Earth.addOrganism(11,11,MaciejJakubowski);
    Earth.display();
    char wait;
    while(Earth.getAtOrder(0)->drawYourself() == 'H') {
      Earth.display();
      Earth.makeTour();
    }






    return 0;
}