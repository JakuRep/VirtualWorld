//
// Created by majaku on 18.04.18.
//

#include "Wolf.h"
Wolf::Wolf(World * myWorld) :
        Animal(myWorld) {
    this->setPriority(5);
    this->setStrenght(9);
}
bool Wolf::collision(Organism * orgPtr) {
    return true;
}

void Wolf::action() {
    move();
}

char Wolf::drawYourself() {
    return 'W';
}
Organism* Wolf::getNewKid() {
    return new Wolf(this->getWorld());
}