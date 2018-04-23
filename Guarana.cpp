//
// Created by majaku on 18.04.18.
//

#include "Guarana.h"
Guarana::Guarana(World *MyWorld) :
        Plant(MyWorld) {
    this->setStrenght(0);
    this->setPriority(0);
}

bool Guarana::collision(Organism *orgPtr) {
    int strenght = orgPtr->getStrenght();
    orgPtr->setStrenght(strenght + 3);
    return true;
}

void Guarana::action() {
    sow();
}
char Guarana::drawYourself() {
    return 'e';
}
Organism * Guarana::getChild() {
    return new Guarana(getWorld());
}
