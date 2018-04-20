//
// Created by majaku on 16.04.18.
//

#ifndef VIRTUALWORLD_PLANT_H
#define VIRTUALWORLD_PLANT_H
#include "Organism.h"

class Plant: public Organism {
private:
    //pass
public:
    Plant(World * myWorld=nullptr);
    void sow();
    char drawYourself() override;
    void action() override;
    bool collision(Organism *  orgPtr) override;

};


#endif //VIRTUALWORLD_PLANT_H
