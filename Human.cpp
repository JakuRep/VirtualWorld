//
// Created by majaku on 22.04.18.
//
#include <ncurses.h>
#include "Human.h"
#include "World.h"
#include "Animal.h"
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
    cbreak();
    noecho();
    keypad(stdscr, true);

        newX = crntX;
        newY = crntY;
        switch (c = getch()) {
            case KEY_UP:
                newY--;
                break;

            case KEY_DOWN:
                newY++;
                break;

            case KEY_RIGHT:
                newX++;
                break;

            case KEY_LEFT:
                newX--;
                break;
        }
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

void Human::walk(int x, int y) {
    World * currentWorld = getWorld();

}