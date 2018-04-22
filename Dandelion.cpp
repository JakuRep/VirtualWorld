//
// Created by majaku on 18.04.18.
//

#include "Dandelion.h"
Dandelion::Dandelion(World *MyWorld) :
    Plant(MyWorld){
        this->setStrenght(0);
        this->setPriority(0);
    };

bool Dandelion::collision(Organism *orgPtr) {
    return true;
}
void Dandelion::action() {
    for(int i = 0; i < 3; i++) {
        sow();
    }
}

char Dandelion::drawYourself() {
    return 'm';
}
Organism * Dandelion::getChild() {
    return new Dandelion(getWorld());
}