//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_GRASS_H
#define VIRTUALWORLD_GRASS_H
#include "Plant.h"

class Grass: public Plant {
public:
    Grass(World *MyWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getChild() override;
};


#endif //VIRTUALWORLD_GRASS_H
