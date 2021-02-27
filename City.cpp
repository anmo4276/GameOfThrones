#include <iostream>
#include <string>
#include "City.h"
using namespace std;
        City::City(){
            letter="";
            cityName = "";
            cityMoney= 0;
            cityArmySize = 0;
            cityPoints=0;
        }
        void City::setLetter(string letterPublic){
            letter = letterPublic;
        }
        string City::getLetter(){
            return letter;
        }
        void City::setCityName(string cityNamePublic){
            cityName = cityNamePublic;
        }
        string City::getCityName(){
            return cityName;
        }
        void City::setCityMoney(int cityMoneyPublic){
            cityMoney = cityMoneyPublic;
        }
        int City::getCityMoney(){
            return cityMoney;
        }
        void City::setCityArmySize(int cityArmySizePublic){
            cityArmySize = cityArmySizePublic;
        }
        int City::getCityArmySize(){
            return cityArmySize;
        }
        void City::setCityPoints(int cityPointsPublic){
            cityPoints = cityPointsPublic;
        }
        int City::getCityPoints(){
            return cityPoints;
        }