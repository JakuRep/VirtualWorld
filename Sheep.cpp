//
// Created by majaku on 18.04.18.
//

#include "Sheep.h"

Sheep::Sheep(World * myWorld) :
        Animal(myWorld) {
    this->setPriority(4);
    this->setStrenght(4);
};

bool Sheep::collision(Organism * orgPtr) {
    std::cout << " owca zostala zaatakowana, staje do walki! ";
    return true;
}
void Sheep::action() {
    std::cout << " Owca rozpoczyna swoja ture\n";
    move();
};
char Sheep::drawYourself() {
    return 'O';
}
Organism* Sheep::getNewKid() {
    return new Sheep(this->getWorld());

}