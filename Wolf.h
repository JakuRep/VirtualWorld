//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_WOLF_H
#define VIRTUALWORLD_WOLF_H
#include "Animal.h"

class Wolf: public Animal {
private:
    //pass
public:
    Wolf(World* myWorld=nullptr);
    void collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getNewKid() override;

};


#endif //VIRTUALWORLD_WOLF_H
