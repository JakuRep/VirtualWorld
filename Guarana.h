//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_GUARANA_H
#define VIRTUALWORLD_GUARANA_H
#include "Plant.h"

class Guarana: public Plant {
public:
    Guarana(World *MyWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getChild() override;
};


#endif //VIRTUALWORLD_GUARANA_H
