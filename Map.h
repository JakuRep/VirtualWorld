//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_MAP_H
#define VIRTUALWORLD_MAP_H
#include "Organism.h"
class Map {
private:
    Organism *** field;
    int width;
    int height;
public:
    //constructor and destructor
    Map(int width = 20, int height = 20);
    ~Map();
    //getters
    Organism * getOrganism(int x, int y);
    int getWidth();
    int getHeight();

    void display();
    bool isInMap(int x, int y);

    void addOrganism(int x, int y, Organism* orgPtr);
    //move Organism return true if new field is empty
    //return false if sth is standing on that field
    bool moveOrganism(int oldX, int oldY, int newX, int newY);
    void killOrganism(int x, int y);


};


#endif //VIRTUALWORLD_MAP_H
