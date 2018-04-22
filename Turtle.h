//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_TURTLE_H
#define VIRTUALWORLD_TURTLE_H
#include "Animal.h"

class Turtle: public Animal {
public:
    Turtle(World* myWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getNewKid() override;
};


#endif //VIRTUALWORLD_TURTLE_H
