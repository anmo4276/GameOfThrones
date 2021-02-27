#include <iostream>
#include <string>
using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior
{
    private:
        string warriorName;
        int strength;
        int loyalty;
        int morale;
        string freeVar;
        string shipWarrior;
        string has_dragonglass;
        
    public:
        Warrior();
        void setWarriorName(string warriorNamePublic);
        string getWarriorName();
        void setWarriorStrength(int strengthPublic);
        int getWarriorStrength();
        void setWarriorLoyalty(int loyaltyPublic);
        int getWarriorLoyalty();
        void setWarriorMorale(int moralePublic);
        int getWarriorMorale();
        void setWarriorFree(string freeVarPublic);
        string getWarriorFree();
        void setWarriorShip(string shipWarriorPublic);
        string getWarriorShip();
        void setWarriorDragonlass(string dragonlassPublic);
        string getWarriorDragonlass();
};

#endif