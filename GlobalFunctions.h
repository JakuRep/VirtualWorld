//
// Created by majaku on 18.04.18.
//

#ifndef VIRTUALWORLD_GLOBALFUNCTIONS_H
#define VIRTUALWORLD_GLOBALFUNCTIONS_H
#include <exception>
using namespace std;

class unknownOrganismType: public exception {
    const char* what() const throw() {
        return "unknown organism type";
    }
};

#endif //VIRTUALWORLD_GLOBALFUNCTIONS_H
