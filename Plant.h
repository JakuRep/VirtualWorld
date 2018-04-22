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
    virtual Organism * getChild() = 0;

};


#endif //VIRTUALWORLD_PLANT_H
