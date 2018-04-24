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
    this->tourOfActivation = -100;
}
bool Human::collision(Organism *orgPtr) {
    std::cout << " czlowiek zaatakwany! staje do walki ";
    return true;
}
void Human::action() {

    std::cout << "czlowiek rozpoczyna swoja ture\n";
    int crntX = getX(), crntY = getY(), newY = crntY, newX = crntX;
    World* CurrentWorld = getWorld();
    int c;
    int value;

    if(getWorld()->getAge() - tourOfActivation < 3) {
        if(rand()%2) {
            value = 2;
        } else {
            value = 1;
        }
    } else {
        value = 1;
    }


    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
        newX = crntX;
        newY = crntY;
    c = getch();
        switch (c) {
            case KEY_UP:
                newY+=value;
                break;

            case KEY_DOWN:
                newY-=value;
                break;

            case KEY_LEFT:
                newX-=value;
                break;

            case KEY_RIGHT:
                newX+=value;
                break;
            case 's':
                c = getch();
                value = 2;
                switch (c) {
                    case KEY_UP:
                        newY+=value;
                        break;

                    case KEY_DOWN:
                        newY-=value;
                        break;

                    case KEY_LEFT:
                        newX-=value;
                        break;

                    case KEY_RIGHT:
                        newX+=value;
                        break;
                }
                activateSuperPower();

                break;
            default:
                newX+=value;
                return;
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
    system("clear");
}
char Human::drawYourself() {
    return 'H';
}
Organism* Human::getNewKid() {
    return nullptr;
}
void Human::activateSuperPower() {
    if(getWorld()->getAge() - tourOfActivation > 5)
        this->tourOfActivation = getWorld()->getAge();
}