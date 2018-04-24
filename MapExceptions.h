//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_MAPEXCEPTIONS_H
#define VIRTUALWORLD_MAPEXCEPTIONS_H

#include <exception>
using namespace std;
class outOfBoundsException: public exception {
    const char* what() const throw() {
        return "Field that you try to use is out of bound";
    }
};
class fieldAlreadyTakenException: public exception {
    const char* what() const throw() {
        return "You can't add new organism on taken field";
    }
};
class thereIsNoLifeOnThisFieldException: public exception {
    const char* what() const throw() {
        return "You try to kill sth that doesnt live";
    }
};
class unknownOrganismTypeException: public exception {
    const char* what() const throw() {
        return "Unknown organism type during reading from file";
    }
};


#endif //VIRTUALWORLD_MAPEXCEPTIONS_H
