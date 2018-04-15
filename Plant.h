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
    Plant(int x=0, int y=0,int priority=0, int age=0, World * myWorld=nullptr);
    void akcja();
    void sow();

};


#endif //VIRTUALWORLD_PLANT_H
