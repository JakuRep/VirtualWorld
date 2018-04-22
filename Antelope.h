//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_ANTELOPE_H
#define VIRTUALWORLD_ANTELOPE_H
#include "Animal.h"

class Antelope: public Animal {
public:
    Antelope(World* myWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getNewKid() override;
};


#endif //VIRTUALWORLD_ANTELOPE_H
