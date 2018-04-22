//
// Created by majaku on 18.04.18.
//

#include "Belladonna.h"
#include "World.h"
Belladonna::Belladonna(World *MyWorld) :
        Plant(MyWorld) {
    this->setPriority(0);
    this->setStrenght(99);
}

bool Belladonna::collision(Organism *orgPtr) {
    this->getWorld()->killOrganism(orgPtr);
    return false;
}
void Belladonna::action() {
    sow();
}
char Belladonna::drawYourself() {
    return 'j';
}
Organism * Belladonna::getChild() {
    return new Belladonna(getWorld());
}