//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_SHEEP_H
#define VIRTUALWORLD_SHEEP_H
#include "Animal.h"

class Sheep:public Animal {
private:
    //pass
public:
    Sheep(World * myWorld=nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getNewKid() override;
};


#endif //VIRTUALWORLD_SHEEP_H
