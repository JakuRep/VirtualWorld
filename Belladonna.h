//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_BELLADONNA_H
#define VIRTUALWORLD_BELLADONNA_H
#include "Plant.h"

class Belladonna:public Plant {
public:
    Belladonna(World *MyWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getChild() override;
};


#endif //VIRTUALWORLD_BELLADONNA_H
