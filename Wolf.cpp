//
// Created by majaku on 18.04.18.
//

#include "Wolf.h"
Wolf::Wolf(World * myWorld) :
        Animal(myWorld) {
    this->setPriority(5);
    this->setStrenght(9);
}

void Wolf::collision(Organism * orgPtr) {

}

void Wolf::action() {

}

char Wolf::drawYourself() {
    return 'W';
}
Organism* Wolf::getNewKid() {
    return new Wolf(this->getWorld());
}