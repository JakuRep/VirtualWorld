//
// Created by majaku on 22.04.18.
//
#include <ncurses.h>
#include "Human.h"
#include "World.h"
#include "Animal.h"
#define KU 103
#define KD 108
#define KL 105
#define KR 106
Human::Human(World * myWorld) :
        Animal(myWorld) {
    this->setStrenght(5);
    this->setPriority(100);
}

bool Human::collision(Organism *orgPtr) {
    return true;
}
void Human::action() {
    int crntX = getX(), crntY = getY(), newY = crntY, newX = crntX;
    World* CurrentWorld = getWorld();
    int c;

    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
        newX = crntX;
        newY = crntY;
    c = getch();
        switch (c) {
            case KEY_UP:
                newY+=1;
                break;

            case KEY_DOWN:
                newY-=1;
                break;

            case KEY_LEFT:
                newX-=1;
                break;

            case KEY_RIGHT:
                newX+=1;
                break;
            default:
                newX+=1;
                break;
        }
        refresh();
        endwin();
    if(getWorld()->isInBound(newX, newY)) {
        if (CurrentWorld->getXY(newX, newY) == nullptr) {
            CurrentWorld->moveOrganism(crntX, crntY, newX, newY);
        } else {
            Organism *orgPtr = this->getWorld()->getXY(newX, newY);
            if (isAnimal(orgPtr) && this->drawYourself() == orgPtr->drawYourself())
                reproduce(orgPtr);
            else {
                if (fight(orgPtr))
                    CurrentWorld->moveOrganism(crntX, crntY, newX, newY);
            }
        }
    }
}

char Human::drawYourself() {
    return 'H';
}

Organism* Human::getNewKid() {
    return nullptr;
}

