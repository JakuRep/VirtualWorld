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
int main() {
    srand(time(NULL));

    int x=0, y=0;
    World Earth = World(20,20);
    Organism * orgPtr = new Sheep(&Earth);
    Organism * orgPtr1 = new Sheep(&Earth);
    Organism * orgPtr2 = new Sheep(&Earth);
    Organism * orgPtr3 = new Sheep(&Earth);
    Organism * orgPtr4 = new Sheep(&Earth);
    Organism * orgPtr5 = new Wolf(&Earth);
    Organism * orgPtr6 = new Wolf(&Earth);
    Earth.addOrganism(0,0,orgPtr2);
    Earth.addOrganism(1,10,orgPtr1);
    Earth.addOrganism(6,15,orgPtr);
    Earth.addOrganism(19,4,orgPtr3);
    Earth.addOrganism(8,13,orgPtr4);
    Earth.addOrganism(10,2,orgPtr5);
    Earth.addOrganism(1,15,orgPtr6);

    Earth.display();
    char wait;
    while(std::cin >> wait) {
      Earth.makeTour();
    }






    return 0;
}