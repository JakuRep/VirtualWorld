//
// Created by majaku on 18.04.18.
//

#include "SosnowskyiHodweed.h"
#include "World.h"
SosnowskyiHodweed::SosnowskyiHodweed(World* MyWorld) :
        Plant(MyWorld) {
    this->setStrenght(10);
    this->setPriority(0);
}

bool SosnowskyiHodweed::collision(Organism *orgPtr) {
    std::cout << "Barszcz Sosnowskiego zabija organizm swoja potworna trucizna\n";
    killOrganism(orgPtr);
    return false;
}
void SosnowskyiHodweed::action() {
    std::cout << "Barszcz sosnowskiego rozpoczyna czyszcenie organizmow! \n";
    int x=getX(), y=getY();
    int xTmp, yTmp;
    Organism * orgTmp;
    int coordinates[] = {-1,1,-1,0,-1,-1,0,-1,-1,1,1,0,1,1,0,1};
    for(int i = 0; i < 16; i+=2) {
        xTmp = x;
        yTmp = y;
        xTmp += coordinates[i];
        yTmp += coordinates[i+1];
        if(getWorld()->isInBound(xTmp,yTmp)) {
            orgTmp = getWorld()->getXY(xTmp, yTmp);
            if (orgTmp != nullptr && isAnimal(orgTmp))
                getWorld()->killOrganism(orgTmp);
        }
    }
    sow();
}
char SosnowskyiHodweed::drawYourself() {
    return 'b';
}
Organism * SosnowskyiHodweed::getChild() {
    return new SosnowskyiHodweed(getWorld());
}