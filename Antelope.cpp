//
// Created by majaku on 18.04.18.
//
#include "World.h"
#include "Antelope.h"
Antelope::Antelope(World *myWorld) :
    Animal(myWorld){
    this->setStrenght(4);
    this->setPriority(4);
}

bool Antelope::collision(Organism *orgPtr) {
    if(rand() %2) {
        move();
        return false;
    } else {
        return true;
    };
}

void Antelope::action() {
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
                newY += 2;
                break;
            case DOWN:
                newY -= 2;
                break;
            case LEFT:
                newX -= 2;
                break;
            case RIGHT:
                newX += 2;
                break;
        }
        isInBound = CurrentWorld->isInBound(newX, newY);
    }

    if(CurrentWorld->getXY(newX, newY) == nullptr) {
        CurrentWorld->moveOrganism(crntX, crntY, newX, newY);
    } else {
        Organism * orgPtr = this->getWorld()->getXY(newX,newY);
        if(isAnimal(orgPtr) && this->drawYourself() == orgPtr->drawYourself())
            reproduce(orgPtr);
        else {
            if(fight(orgPtr))
                CurrentWorld->moveOrganism(crntX, crntY, newX, newY);
        }
    }
}

char Antelope::drawYourself() {
    return 'A';
}

Organism * Antelope::getNewKid() {
    return new Antelope(getWorld());
}