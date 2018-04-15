//
// Created by majaku on 16.04.18.
//

#include "Plant.h"
#include "World.h"
Plant::Plant(int x, int y, int priority, int age, World * myWorld) :
    Organism(x, y, priority, age, myWorld) {};

void Plant::akcja() {
    sow();
}
void Plant::sow() {
    int x = getX(),  y = getY();
    if(findFreeSpace(x,y)) {

        Organism * ptr = new Plant(x, y, this->getPriority(), getWorld()->getAge(), getWorld());
        getWorld()->addOrganism(x,y, ptr);
    } else {
        std::cout << "nie da sie rozmnozyc elo";
    }
};