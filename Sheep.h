//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_SHEEP_H
#define VIRTUALWORLD_SHEEP_H
#include "Animal.h"

class Sheep:public Animal {
public:
private:
    Sheep(int x=0, int y=0,int priority=0, int age=0,int strenght = 0,  World * myWorld=nullptr);
    void collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
};


#endif //VIRTUALWORLD_SHEEP_H
