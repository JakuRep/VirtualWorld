//
// Created by majaku on 22.04.18.
//

#ifndef VIRTUALWORLD_HUMAN_H
#define VIRTUALWORLD_HUMAN_H
#include "Animal.h"

class Human: public Animal {
private:
    int tourOfActivation;
public:
    Human(World* myWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getNewKid() override;
    void activateSuperPower();

};


#endif //VIRTUALWORLD_HUMAN_H
