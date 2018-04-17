//
// Created by majaku on 15.04.18.
//

#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int size) {
    this->size = size;
    this->Queue = new Organism*[size];
    for(int i = 0; i < size; i++)
        Queue[i] = nullptr;

}
PriorityQueue::~PriorityQueue() {
    for(int i = 0; i < size; i++)
        delete Queue[i];
    delete Queue;
}
void PriorityQueue::display() {
    for(int i = 0; i < size; i++) {
        if(Queue[i] != nullptr) {
            std::cout << Queue[i]->getPriority() << " " << Queue[i]->getAge();
            std::cout << std::endl;
        }
    }
}
int PriorityQueue::getSize() {
    return this->size;
}
bool PriorityQueue::isPriorityBigger(Organism *orgOne, Organism *orgTwo) {
    if(orgOne == nullptr && orgTwo == nullptr) {
        return false;

    } else if(orgOne == nullptr && orgTwo != nullptr) {
        return false;

    } else if(orgOne != nullptr && orgTwo == nullptr) {
        return true;

    } else {
        if(orgOne->getPriority() > orgTwo->getPriority())
            return true;

        else if (orgOne->getPriority() < orgTwo->getPriority())
            return false;
        else {
            if(orgOne->getAge() < orgTwo->getAge())
                return true;
            else
                return false;
        }
    }
}
void PriorityQueue::sortQueue() {
    int i, j;
    Organism * tmp;
    bool isSorted = 0;

    for (i = 0; i < size - 1 && !isSorted; i++) {
        isSorted = 1;
        for (j = 0; j < size - i - 1; j++) {
            if (isPriorityBigger(Queue[j+1], Queue[j])) {
                tmp = Queue[j];
                Queue[j] = Queue[j+1];
                Queue[j+1] = tmp;
                isSorted = 0;
            }
        }
    }

    for(i = 0; i < size; i++){
        if(Queue[i] == nullptr) {
            //pass
        } else {
            Queue[i]->setOrder(i);
        }
    }
}
void PriorityQueue::addOrganism(Organism *orgPtr) {
    if(Queue[size-1] != nullptr) {
        throw fullQueueException();
    } else {
        Queue[size-1]=orgPtr;
        sortQueue();
    }
}


void PriorityQueue::killOrganism(Organism * orgPtr) {

    if(orgPtr == nullptr)
        throw noOrganismWithThisPriorityException();
    else {
        int order = orgPtr->getOrder();
        Queue[order] = nullptr;
    }

    sortQueue();
}
Organism* PriorityQueue::getPtrAtOrder(int order) {
    if(order < 0 || order > size) {
        throw outOfBoardException();
    } else {
        return Queue[order];
    }
}

void PriorityQueue::makeTour() {
    for(int i = 0; i < size && Queue[i] != nullptr; i++) {
        Queue[i]->akcja();
    }
}