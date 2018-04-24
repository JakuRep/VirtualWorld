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
    Earth.addOrganism(1,1,new Sheep(&Earth));
    Earth.addOrganism(1,2,new Sheep(&Earth));
    Earth.addOrganism(1,3,new Sheep(&Earth));
    Earth.addOrganism(8,8,new Dandelion(&Earth));
    Earth.addOrganism(3,3,new Wolf(&Earth));
    Earth.addOrganism(3,5,new Wolf(&Earth));
    Earth.addOrganism(3,4,new Wolf(&Earth));
    Earth.addOrganism(6,6,MaciejJakubowski);
    Earth.display();
    char wait;

    while(Earth.getAtOrder(0)->drawYourself() == 'H') {
      Earth.makeTour();
    }






    return 0;
}