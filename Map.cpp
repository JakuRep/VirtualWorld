//
// Created by majaku on 15.04.18.
//
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#include "Map.h"
#include <iostream>
#include "MapExceptions.h"
#include "Organism.h"
#include "Antelope.h"
#include "Belladonna.h"
#include "Dandelion.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "Sheep.h"
#include "SosnowskyiHodweed.h"
#include "Turtle.h"
#include "Wolf.h"

Map::Map(int width, int height) {
    this->width = width;
    this->height= height;
    field = new Organism**[width];
    for(int i = 0; i < width; i++) {
        field[i] = new Organism*[height];
    }
    for(int i = 0; i < width;i++) {
        for(int j = 0; j < height; j++) {
            field[i][j] = nullptr;
        }
    }

}
Map::~Map() {
    for(int i = 0; i < width; i++){
        delete field[i];
    }
    delete field;
}
Organism * Map::getOrganism(int x, int y) {
    if(!isInMap(x,y))
        throw outOfBoundsException();

    return field[x][y];
}
int Map::getWidth() {
    return width;
}
int Map::getHeight() {
    return height;
}
void Map::display() {
    for(int i = 0; i < 3*width + 1; i++)
        putchar('#');

    for(int i = height; i >= 0; i--) {
        std::cout << "#";
        for(int j = 0; j < width; j++) {
            std::cout << " ";
            if(field[j][i] == nullptr)
                std::cout << " ";
             else
                putchar(field[j][i]->drawYourself());
            std::cout << " ";
        }
        std::cout << "#" << std::endl;
    }

    for(int i = 0; i < 3*width + 2; i++)
        putchar('#');
}
bool Map::isInMap(int x, int y) {
    if(x >= 0 && x < width && y >= 0 && y < height)
        return true;
    else
        return false;

}
void Map::addOrganism(int x, int y, Organism * orgPtr) {
    if(!isInMap(x,y))
        throw outOfBoundsException();
    else if(isInMap(x,y) && field[x][y] == nullptr) {
        field[x][y] = orgPtr;
        orgPtr->setX(x);
        orgPtr->setY(y);
    }
    else
        throw fieldAlreadyTakenException();

}
bool Map::moveOrganism(int oldX, int oldY, int newX, int newY) {
    if(!isInMap(newX,newY)) {
        throw outOfBoundsException();
    } else if(field[newX][newY] == nullptr) {
        field[newX][newY] = field[oldX][oldY];
        field[oldX][oldY] = nullptr;
        field[newX][newY]->setX(newX);
        field[newX][newY]->setY(newY);
        return true;
    } else {
        return false;
    }
}
void Map::killOrganism(Organism *orgPtr) {
    int x = orgPtr->getX(), y = orgPtr->getY();
    field[x][y] = nullptr;

}
void Map::readOrganism(int x, int y,Organism * orgPtr) {
    if(isInMap(x,y)) {
        throw outOfBoundsException();
    } else {
        field[x][y] = orgPtr;
    }
}
void Map::cleanMap() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            field[i][j] = nullptr;
        }
    }
}