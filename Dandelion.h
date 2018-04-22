//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_DANDELION_H
#define VIRTUALWORLD_DANDELION_H
#include "Plant.h"

class Dandelion: public Plant {
        public:
        Dandelion(World *MyWorld = nullptr);
        bool collision(Organism * orgPtr) override;
        void action() override;
        char drawYourself() override;
        Organism * getChild() override;
};
#endif //VIRTUALWORLD_DANDELION_H
