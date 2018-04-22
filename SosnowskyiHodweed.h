//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_SOSNOWSKYIHODWEED_H
#define VIRTUALWORLD_SOSNOWSKYIHODWEED_H
#include "Plant.h"

class SosnowskyiHodweed: public Plant {
public:
    SosnowskyiHodweed(World *MyWorld = nullptr);
    bool collision(Organism * orgPtr) override;
    void action() override;
    char drawYourself() override;
    Organism * getChild() override;

};


#endif //VIRTUALWORLD_SOSNOWSKYIHODWEED_H
