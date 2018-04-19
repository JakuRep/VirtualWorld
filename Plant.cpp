//
// Created by majaku on 16.04.18.
//

#include "Plant.h"
#include "World.h"
Plant::Plant(World * myWorld) :
    Organism(myWorld) {};

void Plant::action() {
    sow();
}
void Plant::sow() {
    int x = getX(),  y = getY();
    if(findFreeSpace(x,y)) {

        Organism * ptr = new Plant(getWorld());
        getWorld()->addOrganism(x,y,ptr);
    } else {
        //pass
    }
};

char Plant::drawYourself() {
    return 'p';
}

void Plant::collision(Organism * orgPtr) {
   //pass
}