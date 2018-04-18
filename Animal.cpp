//
// Created by majaku on 18.04.18.
//

#include "Animal.h"
#include "World.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#include "MapExceptions.h"
#include "GlobalFunctions.h"
Animal::Animal(int x, int y, int priority, int age, World * myWorld) :
        Organism(x, y, priority, age, myWorld) {};

void Animal::move() {
    int crntX, crntY, newX, newY, direction;
    bool isInBound = false;
    World * CurrentWorld = this->getWorld();

    crntX = this->getX();
    crntY = this->getY();

    while(!isInBound) {

        direction = rand() % 4;
        newX = crntX;
        newY = crntY;

        switch (direction) {
            case UP:
                newY += 1;
                break;
            case DOWN:
                newY -= 1;
                break;
            case LEFT:
                newX -= 1;
                break;
            case RIGHT:
                newX += 1;
                break;
        }
        isInBound = CurrentWorld->isInBound(newX, newY);
    }

    if(CurrentWorld->getXY(newX, newY) == nullptr) {
        CurrentWorld->moveOrganism(crntX, crntY, newX, newY);
    } else {
        collision(CurrentWorld->getXY(newX, newY));
    }


}
void Animal::collision(Organism * orgPtr) {
    if(orgPtr == nullptr)
        throw thereIsNoLifeOnThisFieldException();
    else if(isAnimal(orgPtr->drawYourself())) {
        if(this->drawYourself() == orgPtr->drawYourself()) {
            reproduce(orgPtr);
        } else {
            //
        }
    } else {

    }
}

void Animal::action() {
    this->move();
}

char Animal::drawYourself() {
    return 'A';

}

void Animal::reproduce(Organism * orgPtr) {

}

bool Animal::amIStronger(Organism *orgPtr) {
    return true;
}

