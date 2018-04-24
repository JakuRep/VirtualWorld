//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_PRIORITYQUEUE_H
#define VIRTUALWORLD_PRIORITYQUEUE_H
#include "QueueExceptions.h"
#include <queue>

class Organism;
class PriorityQueue {
private:
    Organism ** Queue;
    int size;
    int tour;
    std::queue <Organism*> toFree;
 public:
    explicit PriorityQueue(int size = 20*20);
    ~PriorityQueue();
    void display();
    Organism* getPtrAtOrder(int order);
    int getSize();
    bool isPriorityBigger(Organism * orgOne, Organism * orgTwo);
    void sortQueue();
    void addOrganism(Organism * orgPtr);
    void makeTour();
    int getTour();
    void cleanDeadBodies();
    void freezeCorps(Organism * orgPtr);
    void killOrganism(Organism* orgPtr);
    void readOrganism(Organism* orgPtr);
    void cleanQueue();
    void setAge(int age);

};
#include "Organism.h"

#endif //VIRTUALWORLD_PRIORITYQUEUE_H
