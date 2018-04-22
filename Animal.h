//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_ANIMAL_H
#define VIRTUALWORLD_ANIMAL_H

#include "Organism.h"

class Animal: public Organism {
private:
public:

    Animal(World * myWorld=nullptr);

    bool isAnimal(Organism * orgPtr);
    bool isSpieceTheSame(Organism * orgPtr);
    void move();
    void reproduce(Organism* orgPtr);
    int amIStronger(Organism * orgPtr);
    bool fight(Organism *orgPtr);
    virtual Organism * getNewKid() = 0;
};


#endif //VIRTUALWORLD_ANIMAL_H
