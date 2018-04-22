//
// Created by majaku on 18.04.18.
//

#include "Turtle.h"
Turtle::Turtle(World *myWorld) :
        Animal(myWorld) {
    this->setStrenght(2);
    this->setPriority(1);
}

bool Turtle::collision(Organism *orgPtr) {
    if(orgPtr->getStrenght() < 5) {
        return false;
    } else {
        return true;
    }
}

void Turtle::action() {
    if(rand() % 4 == 0)
        move();
}

char Turtle::drawYourself() {
    return 'Z';
}

Organism * Turtle::getNewKid() {
    return new Turtle(getWorld());
}