//
// Created by majaku on 16.04.18.
//

#include "Plant.h"
#include "World.h"
Plant::Plant(World * myWorld) :
    Organism(myWorld) {};

void Plant::sow() {
    int x = getX(),  y = getY();
    if(findFreeSpace(x,y)) {

        Organism * ptr = this->getChild();
        getWorld()->addOrganism(x,y,ptr);
    } else {
        //pass
    }
};
bool Plant::isAnimal(Organism *orgPtr) {
    if(orgPtr->drawYourself() >= 'A' && orgPtr->drawYourself() <= 'Z')
        return true;
    else
        return false;
}