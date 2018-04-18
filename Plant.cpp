//
// Created by majaku on 16.04.18.
//

#include "Plant.h"
#include "World.h"
Plant::Plant(int x, int y, int priority, int age, World * myWorld) :
    Organism(x, y, priority, age, myWorld) {};

void Plant::action() {
    sow();
}
void Plant::sow() {
    int x = getX(),  y = getY();
    if(findFreeSpace(x,y)) {

        Organism * ptr = new Plant(x, y, this->getPriority(), getWorld()->getAge(), getWorld());
        getWorld()->addOrganism(x,y, ptr);
    } else {
        //pass
    }
};

char Plant::drawYourself() {
    return 'P';
}

void Plant::collision(int x, int y) {
   //pass
}