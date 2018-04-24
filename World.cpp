//
// Created by majaku on 15.04.18.
//

#include "World.h"
#include "Organism.h"
#include "MapExceptions.h"
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
#include "Human.h"

World::World(int width, int height) {
    GameMap =new Map(width, height);
    GameQueue =new PriorityQueue(width*height);
}
World::~World() {
    delete GameMap;
    delete GameQueue;
}
int World::getSize() {
    return GameQueue->getSize();
}
int World::getWidth() {
    return GameMap->getWidth();
}
int World::getHeight() {
    return GameMap->getWidth();
}
int World::getAge() {
    return this->GameQueue->getTour();
}
void World::setAge(int age) {
    this->GameQueue->setAge(age);
}
Organism * World::getXY(int x, int y) {
    return (GameMap->getOrganism(x,y));
}
bool World::moveOrganism(int oldX, int oldY, int newX, int newY) {
    return GameMap->moveOrganism(oldX, oldY, newX, newY);
}
void World::addOrganism(int x, int y, Organism *orgPtr) {
    GameMap->addOrganism(x,y,orgPtr);
    GameQueue->addOrganism(orgPtr);
}
void World::killOrganism(Organism *orgPtr) {
    GameQueue->killOrganism(orgPtr);
    GameMap->killOrganism(orgPtr);
}
void World::makeTour() {
    GameQueue->makeTour();
    GameQueue->cleanDeadBodies();
    display();
}
void World::display() {

    GameQueue->display();
    std::cout << "\n";

    GameMap->display();
    std::cout << "\n\n";
}
bool World::isInBound(int x, int y) {
    return GameMap->isInMap(x,y);
}
Organism * World::getAtOrder(int order) {
    return GameQueue->getPtrAtOrder(order);
}

void World::saveGame() {
    char* saveName, spiece;
    int height, width, x, y, strenght, age;
    Organism * orgPtr;
    FILE * save;
    system("clear");
    std::cout << "Write name of file";
    std::cin >> saveName;
    save = fopen(saveName, "w");
    //reading World Parameters
    width = getWidth();
    height = getHeight();
    age = getAge();

    fprintf(save, "width: %d|", width);
    fprintf(save, "height: %d|", height);
    fprintf(save, "age: %d|", age);


    //reading and saving organisms;
    for(int i = 0; GameQueue->getPtrAtOrder(i) != nullptr; i++) {
        orgPtr = GameQueue->getPtrAtOrder(i);
        spiece = orgPtr->drawYourself();
        x = orgPtr->getX();
        y = orgPtr->getY();
        strenght = orgPtr->getStrenght();
        age = orgPtr->getAge();
        fprintf(save, "spiece: %c|strenght: %d|age: %d|x: %d| y:%d|", spiece, strenght, age, x, y);
    }



}

void World::readGame() {

    //reading file
    FILE * read;
    char * filename;
    std::cout << "please write name of file";
    scanf("%s", filename);
    read = fopen(filename, "r");
    if(read != NULL) {
        //prepearing world for reading game
        GameQueue->cleanQueue();
        GameMap->cleanMap();
        delete GameQueue;
        delete GameMap;

        int width, height, age;
        width = fscanf(read, "width: %d", &width);
        height = fscanf(read, "|height %d", &height);
        age = fscanf(read, "|age: %d", &age);

        GameQueue = new PriorityQueue(width * height);
        GameMap = new Map(width, height);
        GameQueue->setAge(age);
        Organism *orgPtr;
        if(true) {
            char spiece;
            int strenght, x, y;
            fscanf(read, "|spiece: %c|strenght: %d|age: %d|x: %d| y:%d", &spiece, &strenght, &age, &x, &y);

            switch (spiece) {
                case 'A':
                    orgPtr = new Antelope(this);
                    break;
                case 'j':
                    orgPtr = new Belladonna(this);
                    break;
                case 'm':
                    orgPtr = new Dandelion(this);
                    break;
                case 'L':
                    orgPtr = new Fox(this);
                    break;
                case 'g':
                    orgPtr = new Grass(this);
                    break;
                case 'e':
                    orgPtr = new Guarana(this);
                    break;
                case 'H':
                    orgPtr = new Human(this);
                    break;
                case 'O':
                    orgPtr = new Sheep(this);
                    break;
                case 'b':
                    orgPtr = new Belladonna(this);
                    break;
                case 'Z':
                    orgPtr = new Turtle(this);
                    break;
                case 'W':
                    orgPtr = new Wolf(this);
                    break;
                defaul:
                    throw unknownOrganismTypeException();
            }

            orgPtr->setAge(age);
            orgPtr->setStrenght(strenght);
            GameMap->readOrganism(x, y, orgPtr);
            GameQueue->readOrganism(orgPtr);
        }
    }
}
