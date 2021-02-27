#include <iostream>
#include <string>
#include "Map.h"
#include <fstream>
using namespace std;
int split(string phrase, char splitChar, string store[],int length)
{
    int count=0; //Initializes a variable of type integer named count and sets it equal to 0
    int i =0; //Initializes a variable of type integer named i and sets it equal to 1
    int index=0;
    store[length];
    if(phrase.length()!=0) //If the string length is not 0
    {
        count=1; //The count is one
    }
    else if(phrase.length() == 1 && phrase[0]!= splitChar) //If string length is one and its not a delimeter
    {
        count = 0; //The count is 0
    }
    if(splitChar == phrase[0]) //If the first character is a delimeter
    {
        i =1; //Start the for loop at 1
    }
    for (i; i < phrase.length(); i++) //For loop for the length of the string
        {
         if (i == phrase.length()- 1) //If the for loop is on the last character
         {
             if(phrase[i]!=splitChar) // If he last character isn't a delimeter
             {
                  store[index]=store[index]+phrase[i]; //Store the character at i into the array at index
             }
             break; //Exi the for loop
         }
         else if (phrase[i]==splitChar && phrase[i+1]!=splitChar) //Checks if there aren't two delimeter in a row
         {
                 index++; //Add one to index
                 count++; //Adds one to string count
         }
         else if(phrase[i]==splitChar)//If the character at i is a delimeter
         {
             if (phrase[i]==splitChar && phrase[i- 1]!=splitChar)//If the string at i is a delimeter and the one before it isnt:
             {
                 //Do nothing
             }
             else //Else
             {
             if(i!=0)//If it isn't the first character
             {
             index++; //SAdd one to index
             count++; //Add one to count
             }
             }
         }
         else //Else
         {
             store[index] = store[index] + phrase[i]; //Store the character at i into the array at index
         }
         
        }   
        return count; //Return the string count
}
        Map::Map(){
            row=0;
            column=0;
            dragonlassMap = false;
            for(int i=0; i<25;i++){
                for(int j=0; j<16;j++){
                    mapArray[i][j]= " ";
                }
            }
        }
        void Map::setMap(){
            string store[16];
            int index=0;
            ifstream myFile;
            myFile.open("mapGOT.txt");
            if (myFile.is_open()) //If file opens:
            {
                string line = ""; //Line equals ""
        
        
                while (getline(myFile, line))  //For every line in the file:
                {
            
                     if(!line.empty()) //If line isn't empty:
                         {
                             split(line,',',store,16);
                             for(int a =0; a<16;a++){
                                mapArray[index][a] = store[a];
                             }
                         }
                    index++;
                    for(int b=0;b<16;b++){
                        store[b]="";
                    }
                }
            }
            myFile.close();
        }
        void Map::getMap(int rowPublic, int columnPublic){
            for(int a= 0; a<7;a++){
                for(int b =0 ; b<7; b++){
                    
                    if(a == 3 && b ==3){
                        cout<< "[";
                    }
                    if((rowPublic-3)+a < 0 || (columnPublic-3)+b < 0 ){
                        cout<< "?";
                    }
                    else if((rowPublic-3)+a > 24 || (columnPublic-3)+b > 15 ){
                        cout<< "?";
                    }
                    else if(mapArray[(rowPublic-3)+a][(columnPublic-3)+b] == "p"){
                        cout<< "*";
                    }
                    else if(mapArray[(rowPublic-3)+a][(columnPublic-3)+b] == "w"){
                        cout<< "~";
                    }
                    else{
                        cout<< mapArray[(rowPublic-3)+a][(columnPublic-3)+b];
                    }
                    if(a == 3 && b ==3){
                        cout<< "] ";
                    }
                    else if(a == 3 && b ==2){
                        cout<< " ";
                    }
                    else{
                        cout<< "  ";
                    }
                }
                cout<<endl;
            }
        }
        
        string Map::getTile(int rowPublic, int columnPublic){
            return mapArray[rowPublic][columnPublic];
        }
        void Map::setDragonglass(bool dragonlassPublicMap){
            dragonlassMap = dragonlassPublicMap;
        }
        bool Map::getDragonglass(){
            return dragonlassMap;
        }
        