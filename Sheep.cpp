//
// Created by majaku on 18.04.18.
//

#include "Sheep.h"

Sheep::Sheep(World * myWorld) :
        Animal(myWorld) {
    this->setPriority(4);
    this->setStrenght(4);
};

void Sheep::collision(Organism * orgPtr) {
    //pass
}
void Sheep::action() {
    move();
};
char Sheep::drawYourself() {
    return 'S';
}
Organism* Sheep::getNewKid() {
    return new Sheep(this->getWorld());
}