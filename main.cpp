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
    Organism * orgPtr = new Wolf(&Earth);
    Organism * orgPtr1 = new Wolf(&Earth);
    Organism * orgPtr2 = new Wolf(&Earth);
    Organism * orgPtr3 = new Wolf(&Earth);
    Organism * orgPtr4 = new Wolf(&Earth);
    Organism * orgPtr5 = new Wolf(&Earth);
    Organism * orgPtr6 = new Sheep(&Earth);
    Earth.addOrganism(0,0,orgPtr2);
    Earth.addOrganism(0,1,orgPtr1);
    Earth.addOrganism(1,0,orgPtr);
    Earth.addOrganism(2,0,orgPtr3);
    Earth.addOrganism(0,2,orgPtr4);
    Earth.addOrganism(0,3,orgPtr5);
    Earth.addOrganism(3,0,orgPtr6);

    Earth.display();
    char wait;
    while(std::cin >> wait) {
      Earth.makeTour();
    }






    return 0;
}