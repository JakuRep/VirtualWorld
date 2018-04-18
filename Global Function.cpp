//
// Created by majaku on 18.04.18.
//
#include "GlobalFunctions.h"
bool isAnimal(char sign) {

    if(sign >= 'a' && sign <= 'z') {
        return false;
    } else if ( sign >= 'A' && sign <= 'Z') {
        return true;
    } else {
        throw unknownOrganismType();
    }
}

