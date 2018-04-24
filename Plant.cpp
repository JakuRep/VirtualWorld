//
// Created by majaku on 16.04.18.
//

#include "Plant.h"
#include "World.h"
Plant::Plant(World * myWorld) :
    Organism(myWorld) {};

void Plant::sow() {
    int x = getX(),  y = getY();
    std::cout << "proba rozsiewu organizmu typu " << this->drawYourself() << " na polu x: " << x << " y: " << y << std::endl;
    if(findFreeSpace(x,y)) {
        std::cout << "udalo sie rozsiac\n";
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