#include <iostream>
#include <string>
#include "Warrior.h"
using namespace std;
        Warrior::Warrior(){
                warriorName ="";
                strength = 0;
                morale =0;
                freeVar = "";
                shipWarrior ="";
                has_dragonglass = "";
        }
        void Warrior::setWarriorName(string warriorNamePublic){
            warriorName = warriorNamePublic;
        }
        string Warrior::getWarriorName(){
            return warriorName;
        }
        void Warrior::setWarriorLoyalty(int loyaltyPublic){
            loyalty = loyaltyPublic;
        }
        int Warrior::getWarriorLoyalty(){
            return loyalty;
        }
        void Warrior::setWarriorStrength(int strengthPublic){
                strength = strengthPublic;
        }
        int Warrior::getWarriorStrength(){
            return strength;
        }
        void Warrior::setWarriorMorale(int moralePublic){
            morale = moralePublic;
        }
        int Warrior::getWarriorMorale(){
            return morale;
        }
        void Warrior::setWarriorFree(string freeVarPublic){
            freeVar = freeVarPublic;
        }
        string Warrior::getWarriorFree(){
            return freeVar;
        }
        void Warrior::setWarriorShip(string shipWarriorPublic){
            shipWarrior = shipWarriorPublic;
        }
        string Warrior::getWarriorShip(){
            return shipWarrior;
        }
        void Warrior::setWarriorDragonlass(string dragonlassPublic){
            has_dragonglass = dragonlassPublic;
        }
        string Warrior::getWarriorDragonlass(){
            return has_dragonglass;
        }