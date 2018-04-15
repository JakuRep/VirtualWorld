//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_PRIORITYQUEUE_H
#define VIRTUALWORLD_PRIORITYQUEUE_H
#include "QueueExceptions.h"
#include "Organism.h"


class PriorityQueue {
private:
    Organism ** Queue;
    int size;
public:
    PriorityQueue(int size = 20*20);
    ~PriorityQueue();
    void display();
    Organism* getPtrAtOrder(int order);
    int getSize();
    bool isPriorityBigger(Organism * orgOne, Organism * orgTwo);
    void sortQueue();
    void addOrganism(Organism * orgPtr);
    void killOrganism(Organism * orgPtr);

};


#endif //VIRTUALWORLD_PRIORITYQUEUE_H
