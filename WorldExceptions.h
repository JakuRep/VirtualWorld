//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_WORLDEXCEPTIONS_H
#define VIRTUALWORLD_WORLDEXCEPTIONS_H
#include "exception"
using namespace std;

class noOrganismOnThisCoordinatesException: public exception {
    const char* what() const throw() {
        return "no organism at this coordinates";
    }
};


#endif //VIRTUALWORLD_WORLDEXCEPTIONS_H
