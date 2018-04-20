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
Animal::Animal(World * myWorld) :
        Organism(myWorld) {};

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
        Organism * orgPtr = this->getWorld()->getXY(newX,newY);
        if(isAnimal(orgPtr))
            if(isSpieceTheSame(orgPtr))
                reproduce(getWorld()->getXY(newX,newY));
            else
                fight(orgPtr);

    }


}

void Animal::reproduce(Organism * orgPtr) {
    int x = orgPtr->getX(), y=orgPtr->getY();
    if(findFreeSpace(x,y)) {
        Organism * ptr = this->getNewKid();
        getWorld()->addOrganism(x,y,ptr);
    }
}

int Animal::amIStronger(Organism *orgPtr) {
    int strThis = this->getStrenght(), strOther = orgPtr->getStrenght();
    if(strThis > strOther)
        return 1;
    else if(strThis == strOther)
        return 0;
    else
        return -1;

}

bool Animal::isAnimal(Organism * orgPtr) {
    if(orgPtr == nullptr)
        throw thereIsNoLifeOnThisFieldException();

    char sign = orgPtr->drawYourself();

    if(sign >= 'A' && sign <='Z')
        return true;
    else if(sign >='a' && sign <='z')
        return false;
    else {
        throw unknownOrganismType();
    }
}

bool Animal::isSpieceTheSame(Organism *orgPtr) {
    if(this->drawYourself() == orgPtr->drawYourself())
        return true;
    else
        return false;
}

void Animal::fight(Organism * orgPtr) {

    if (orgPtr->collision(this)) {
        if (amIStronger(orgPtr)) {
            int x = orgPtr->getX();
            int y = orgPtr->getY();
            this->getWorld()->killOrganism(orgPtr);
            this->getWorld()->moveOrganism(this->getX(), this->getY(), x, y);
        } else {
            //sgetWorld()->killOrganism(this);
        };
    }
}