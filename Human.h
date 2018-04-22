//
// Created by majaku on 22.04.18.
//

#ifndef VIRTUALWORLD_HUMAN_H
#define VIRTUALWORLD_HUMAN_H
#include "Animal.h"

class Human: public Animal {
public:
    Human(World* myWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getNewKid() override;
};


#endif //VIRTUALWORLD_HUMAN_H
