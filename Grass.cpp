//
// Created by majaku on 18.04.18.
//

#include "Grass.h"
Grass::Grass(World *MyWorld) :
        Plant(MyWorld){
    this->setStrenght(0); this->setPriority(0);
};

bool Grass::collision(Organism *orgPtr) {
    return true;
}
void Grass::action() {
    sow();
}
char Grass::drawYourself() {
    return 'g';
}
Organism * Grass::getChild() {
    return new Grass(getWorld());
}