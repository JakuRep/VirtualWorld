//
// Created by majaku on 16.04.18.
//

#include "Plant.h"
#include "World.h"
Plant::Plant(int x, int y, int priority, int age, int strenght, World * myWorld) :
    Organism(x, y, priority, age, strenght, myWorld) {};

void Plant::action() {
    sow();
}
void Plant::sow() {
    int x = getX(),  y = getY();
    if(findFreeSpace(x,y)) {

        Organism * ptr = new Plant(x, y, this->getPriority(), getWorld()->getAge(),getStrenght(), getWorld());
        getWorld()->addOrganism(x,y, ptr);
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