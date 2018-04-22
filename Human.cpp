//
// Created by majaku on 22.04.18.
//
#include "WorldExceptions.h"
#include "Human.h"
Human::Human(World * myWorld) :
        Animal(myWorld) {
    this->setStrenght(5);
    this->setPriority(100);
}

bool Human::collision(Organism *orgPtr) {
    return true;
}
void Human::action() {

}

char Human::drawYourself() {
    return 'H';
}

Organism* getNewKid() {
        throw humanIsSupposedToHaveAloneLifeWithNoChildsSoWhyHeEvenTryToReproduceException();
}