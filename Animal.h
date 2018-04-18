//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_ANIMAL_H
#define VIRTUALWORLD_ANIMAL_H

#include "Organism.h"

class Animal: public Organism {
private:
public:
    Animal(int x=0, int y=0,int priority=0, int age=0, World * myWorld=nullptr);
    void action() override;
    char drawYourself() override;
    void collision(int x, int y);

    void move();
    void reproduce();
    bool amIStronger(Organism * orgPtr);
};


#endif //VIRTUALWORLD_ANIMAL_H
