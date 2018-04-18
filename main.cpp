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
int main() {
    srand(time(NULL));

    int x=0, y=0;
    World Earth = World(20,20);
    Organism * orgPtr = new Animal(19, 19,2,5,&Earth);
    Organism * orgPtr1 = new Animal(0,0,3,1,&Earth);
    Organism * orgPtr2 = new Animal(0,1,7,7,&Earth);
    //Earth.addOrganism(0,1,orgPtr);
    Earth.addOrganism(2,2,orgPtr2);
    Earth.addOrganism(1,2,orgPtr1);
    Earth.addOrganism(0,2,orgPtr);
    Earth.display();
    for(int i = 0; i < 100; i++) {
      Earth.makeTour();
    }






    return 0;
}