//
// Created by majaku on 18.04.18.
//

#include "Sheep.h"

Sheep::Sheep(int x, int y, int priority, int age, int strenght, World * myWorld) :
        Animal(x, y, priority, age, strenght, myWorld) {};

void Sheep::collision(Organism * orgPtr) {
    if(isAnimal(orgPtr)) {
        if(isSpieceTheSame(orgPtr)) {
            reproduce(orgPtr);
        } else {
            this->fight(orgPtr);
        }
    } else {

    }
}
