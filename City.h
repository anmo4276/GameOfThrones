#include <iostream>
#include <string>
using namespace std;

#ifndef CITY_H
#define CITY_H

class City
{
    private:
        string letter;
        string cityName;
        int cityMoney;
        int cityArmySize;
        int cityPoints;
    
    public:
        City();
        void setLetter(string letterPublic);
        string getLetter();
        void setCityName(string cityNamePublic);
        string getCityName();
        void setCityMoney(int cityMoneyPublic);
        int getCityMoney();
        void setCityArmySize(int cityArmySizePublic);
        int getCityArmySize();
        void setCityPoints(int cityPointsPublic);
        int getCityPoints();
    
};

#endif