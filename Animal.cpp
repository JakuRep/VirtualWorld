//
// Created by majaku on 18.04.18.
//

#include "Animal.h"
#include "World.h"
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
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
            std::cout << "gora\n";
                newY += 1;
                break;
            case DOWN:
                std::cout << "dol\n";
                newY -= 1;
                break;
            case LEFT:
                std::cout << "lewo\n";
                newX -= 1;
                break;
            case RIGHT:
                std::cout << "prawo\n";
                newX += 1;
                break;
        }
        isInBound = CurrentWorld->isInBound(newX, newY);
    }

    if(CurrentWorld->getXY(newX, newY) == nullptr) {
        CurrentWorld->moveOrganism(crntX, crntY, newX, newY);
    } else {
        collision(newX, newY);
    }


}
void Animal::collision(int x, int y) {
    std::cout << "kolizja";
}

void Animal::action() {
    this->move();
}

char Animal::drawYourself() {
    return 'A';

}

void Animal::reproduce() {
    //pass
}

bool Animal::amIStronger(Organism *orgPtr) {
    return true;
}

