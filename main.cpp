#include <iostream>
#include "Map.h"
#include "PriorityQueue.h"
#include "time.h"
#include "Organism.h"
#include <stdlib.h>
#include "World.h"
int main() {

    World MyWorld = World(20,20);
    Organism * org1 = new Organism(0,1);

    Organism * org2 = new Organism(0,2);

    Organism * org3 = new Organism(1,0);

    Organism * org4 = new Organism(1,2);


    Organism * org5 = new Organism(1,3);

    Organism * org6 = new Organism(3,1);

    Organism * org7 = new Organism(3,1);

    Organism * org8 = new Organism(6,1);

    Organism * org9 = new Organism(5,1);

    Organism * org10 = new Organism(3,3);

    Organism * org11 = new Organism(2,0);


    Organism * org12 = new Organism(1,1);

    Organism * org13 = new Organism(1,1);


    Organism * org14 = new Organism(1,1);

    //MyWorld.addOrganism(1,1,org1);

    MyWorld.addOrganism(2,1,org2);

    MyWorld.addOrganism(3,1,org3);

    MyWorld.addOrganism(4,1,org4);

    MyWorld.addOrganism(5,1,org5);

    MyWorld.addOrganism(1,2,org6);

    MyWorld.addOrganism(1,3,org7);

    MyWorld.addOrganism(1,4,org8);

    MyWorld.addOrganism(7,5,org9);
    MyWorld.addOrganism(8,5,org10);
    MyWorld.addOrganism(9,5,org11);
    MyWorld.addOrganism(1,7,org12);
    MyWorld.addOrganism(1,8,org13);
    MyWorld.addOrganism(1,9,org14);
    MyWorld.display();
    return 0;
}