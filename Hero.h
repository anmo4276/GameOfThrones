#include <iostream>
#include <string>
#include "Warrior.cpp"
using namespace std;

#ifndef HERO_H
#define HERO_H

class Hero
{
    private:
        string name;
        int money;
        int influence;
        Warrior warriors[4];
        int armySize;
        int positionRow;
        int positionColumn;
        string ship;
        int points;
        int index;
    public:
        Hero();
        void setHeroName(string namePublic);
        string getHeroName();
        void setHeroMoney(int moneyPublic);
        int getHeroMoney();
        void setWarriors(string warriorsPublic[]);
        Warrior getWarriors(int index);
        void setWarriorStats(int index, Warrior newWarrior);
        void setHeroInfluence(int influencePublic);
        int getHeroInfluence();
        void setArmySize(int armySizePublic);
        int getArmySize();
        void setHeroLocation(int positionRowPublic, int positionColumnPublic);
        int getPositionRow();
        int getPositionColumn();
        void setShip(string shipPublic);
        string getShip();
        void setHeroPoints(int pointsPublic);
        int getHeroPoints();
};

#endif