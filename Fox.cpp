//
// Created by majaku on 18.04.18.
//

#include "Fox.h"
#include "World.h"
Fox::Fox(World *MyWorld) :
        Animal(MyWorld) {
    this->setPriority(7);
    this->setStrenght(3);
}

bool Fox::collision(Organism *orgPtr) {
    return true;
}

void Fox::action() {
    int tmpX, tmpY, crntX = getX(), crntY = getY(), direction = rand()%4;
    World * CurrentWorld = getWorld();
    bool isFieldNotDangerous;
    for(int i = 0; i < 4; i++, direction++ ) {
        direction %=4;
        switch (direction) {
            case UP:
                tmpX = crntX;
                tmpY = crntY - 1;
                break;
            case DOWN:
                tmpX= crntX;
                tmpY = crntY + 1;
                break;
            case LEFT:
                tmpX = crntX -1;
                tmpY = crntY;
                break;
            case RIGHT:
                tmpX = crntX + 1;
                tmpY = crntY;
                break;
        }
        if(getWorld()->isInBound(tmpX, tmpY) &&
           (getWorld()->getXY(tmpX, tmpY) == nullptr ||
            (getWorld()->getXY(tmpX, tmpY)->getStrenght() <= this->getStrenght()) ||
             getWorld()->getXY(tmpX, tmpY)->drawYourself() == this->drawYourself())) {

            isFieldNotDangerous = true;
            break;
        } else {
            isFieldNotDangerous = false;
        }

    }
    if(isFieldNotDangerous) {
        if(CurrentWorld->getXY(tmpX, tmpY) == nullptr) {
            CurrentWorld->moveOrganism(crntX, crntY, tmpX, tmpY);
        } else {
            Organism * orgPtr = this->getWorld()->getXY(tmpX,tmpY);
            if(isAnimal(orgPtr) && this->drawYourself() == orgPtr->drawYourself())
                reproduce(orgPtr);
            else {
                if(fight(orgPtr))
                    CurrentWorld->moveOrganism(crntX, crntY, tmpX, tmpY);
            }
        }
    }
}

char Fox::drawYourself() {
    return 'L';
}

Organism* Fox::getNewKid() {
    return new Fox(getWorld());
}