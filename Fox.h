//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_FOX_H
#define VIRTUALWORLD_FOX_H
#include "Animal.h"

class Fox: public Animal {
public:
       Fox(World* myWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getNewKid() override;

};


#endif //VIRTUALWORLD_FOX_H
