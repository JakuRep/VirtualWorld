//
// Created by majaku on 15.04.18.
//

#ifndef VIRTUALWORLD_ORGANISM_H
#define VIRTUALWORLD_ORGANISM_H


class Organism {
    int order;
    int priority;
    int age;
    int x;
    int y;
public:
    Organism(int priority, int age) {
        this->priority = priority;
        this->age = age;
    }
    int getPriority() {
        return this->priority;
    }
    int getAge() {
        return this->age;
    }
    int getOrder() {
        return this->order;
    }
    void setOrder(int order) {
        this->order = order;
    }
    int getX() {
        return this->x;
    }
    void setX(int x) {
        this->x = x;
    }
    int getY() {
        return this->y;
    }
    void setY(int y) {
        this->y = y;
    }

};


#endif //VIRTUALWORLD_ORGANISM_H
