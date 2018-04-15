//
// Created by majaku on 16.04.18.
//

#ifndef VIRTUALWORLD_ORGANISMEXCEPTIONS_H
#define VIRTUALWORLD_ORGANISMEXCEPTIONS_H
#include <exception>
using namespace std;

class findingFreeSpaceWithEmptyCoordinates: public exception {
    const char* what() const throw() {
        return "yo, u trying to find free space for non existing organism";
    }
};


#endif //VIRTUALWORLD_ORGANISMEXCEPTIONS_H
