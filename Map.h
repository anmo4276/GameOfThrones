#include <iostream>
#include <string>
using namespace std;

#ifndef MAP_H
#define MAP_H

class Map
{
    private:
        int row;
        int column;
        string mapArray[25][16];
        bool dragonlassMap;
    public:
        Map();
        void setMap();
        void getMap(int rowPublic, int columnPublic);
        string getTile(int rowPublic, int columnPublic);
        void setDragonglass(bool dragonlassPublicMap);
        bool getDragonglass();
};

#endif