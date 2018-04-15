//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_QUEUEEXCEPTIONS_H
#define VIRTUALWORLD_QUEUEEXCEPTIONS_H
#include <exception>
using namespace std;

class fullQueueException: public exception {
    const char* what() const throw() {
        return "you trying to add organism to queue when there is no space left";
    }
};

class noOrganismWithThisPriorityException: public exception {
    const char* what() const throw() {
        return "you trying to kill organism that doesnt exist";
    }
};

class outOfBoardException: public exception {
    const char* what() const throw() {
        return "you trying to call index of priorityQueue that is out of bounds";
    }
};
#endif //VIRTUALWORLD_QUEUEEXCEPTIONS_H
