//
// Created by majaku on 18.04.18.
//

#include "Turtle.h"
Turtle::Turtle(World *myWorld) :
        Animal(myWorld) {
    this->setStrenght(2);
    this->setPriority(1);
}
bool Turtle::collision(Organism *orgPtr) {
    std::cout << " Zlow pod atakiem!, probuje odeprzec atak ";
    if(orgPtr->getStrenght() < 5) {
        std::cout << " napastnik okazal sie za slaby na skorupe zlowia, atak odparty\n";
        return false;
    } else {
        std::cout << " skorupa roztrzaskana, zlow walczy ";
        return true;
    }
}
void Turtle::action() {
    std::cout << "zlow rozmysla czy sie poruszyc? ";
    if(rand() % 4 == 0) {
        std::cout << " Tym razem zmienia swoje polozenie\n";
        move();
    } else {
        std::cout << "w tej turze stoi!\n";
    }
}
char Turtle::drawYourself() {
    return 'Z';
}
Organism * Turtle::getNewKid() {
    return new Turtle(getWorld());
}