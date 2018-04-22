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
int main() {
    srand(time(NULL));

    int x=0, y=0;
    World Earth = World(30,30);
    Organism * orgPtr = new Wolf(&Earth);
    Organism * orgPtr1 = new Wolf(&Earth);
    Organism * orgPtr2 = new Wolf(&Earth);
    Organism * orgPtr3 = new Wolf(&Earth);
    Organism * orgPtr4 = new Wolf(&Earth);
    /*
    Organism * orgPtr5 = new Sheep(&Earth);
    Organism * orgPtr6 = new Sheep(&Earth);
    Organism * orgPtr7 = new Grass(&Earth);
    Organism * orgPtr8 = new Grass(&Earth);
    Organism * orgPtr9 = new Grass(&Earth);
    Organism * orgPtr10 = new Grass(&Earth);
    Organism * orgPtr11 = new Grass(&Earth);
    Organism * orgPtr12 = new Grass(&Earth);
    Organism * orgPtr13 = new Grass(&Earth);
    Organism * orgPtr14 = new Sheep(&Earth);
    Organism * orgPtr15 = new Sheep(&Earth);
    Organism * orgPtr16 = new Sheep(&Earth);
    Organism * orgPtr17 = new Sheep(&Earth);
    Organism * orgPtr18 = new Sheep(&Earth);
    Organism * orgPtr19 = new Sheep(&Earth);

    Organism * orgPtr101 = new Grass(&Earth);
    Organism * orgPtr112 = new Grass(&Earth);
    Organism * orgPtr123 = new Grass(&Earth);
    Organism * orgPtr134 = new Grass(&Earth);
    Organism * orgPtr145 = new Grass(&Earth);
    Organism * orgPtr156 = new Grass(&Earth);
    Organism * orgPtr167 = new Grass(&Earth);
    Organism * orgPtr178 = new Grass(&Earth);
    Organism * orgPtr189 = new Grass(&Earth);
*/
    Earth.addOrganism(0,0,orgPtr2);
    Earth.addOrganism(0,1,orgPtr1);
    Earth.addOrganism(1,0,orgPtr);
    Earth.addOrganism(2,0,orgPtr3);
    Earth.addOrganism(0,2,orgPtr4);/*
    Earth.addOrganism(0,3,orgPtr5);
    Earth.addOrganism(3,0,orgPtr6);
    Earth.addOrganism(14,14,orgPtr14);
    //Earth.addOrganism(16,1,orgPtr13);
    //Earth.addOrganism(19,1,orgPtr12);
    //Earth.addOrganism(18,1,orgPtr11);
    //Earth.addOrganism(17,1,orgPtr10);
    //Earth.addOrganism(0,19,orgPtr9);
    //Earth.addOrganism(0,18,orgPtr8);
    ;
    Earth.addOrganism(20,1,orgPtr14);
    Earth.addOrganism(21,1,orgPtr15);
    Earth.addOrganism(22,1,orgPtr16);
    Earth.addOrganism(23,1,orgPtr17);
    Earth.addOrganism(24,19,orgPtr18);
    Earth.addOrganism(25,18,orgPtr19);
*/
    Earth.display();
    char wait;
    while(std::cin >> wait) {
      Earth.makeTour();
    }






    return 0;
}