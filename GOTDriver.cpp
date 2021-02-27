#include <iostream>
#include <string>
#include "Hero.cpp"
#include "Map.cpp"
#include "City.cpp"
#include <fstream>
#include <stdlib.h>
using namespace std;

int randomNum(){
    return random() % 4 + 1; //Random number between 1 and 4
}

bool randomProb(double prob){
    int random2= random() % 100 + 1; //Random num between 1 and 100
    if(random2<=prob) //If inputed number is less than random number:
    {
        return true;//Return true
    }
    else{ //Else:
        return false; //Return false
    }
}

bool encounter(int row, int column, int row2, int column2)
{
    int absX= abs(column-column2); //Calculate difference in columns
    int absY= abs(row-row2); //Calculate difference between rows 
    if(absX<=2 && absY <=2){ //If another hero is within a 2 block radius:
        return true;//Return true
    }
    return false; //Return false
}

bool caseInsensitive(string usernameOne, string usernameTwo)
{
    
    if(usernameOne.length()!= usernameTwo.length()) //If the lengths of the two strings are unequal:
    {
        return false; //return false
    }
    int sameLetter=0; //Initializes integer variable named sameLetter and sets it equal to 0
    int firstLetter; //Initializes integer variable named firstLetter
    int secondLetter; //Initializes integer variable named secondLetter
    for(int a =0; a <usernameOne.length(); a++) //For every character in usernameOne
    {
        firstLetter = usernameOne[a]; //first Letter equals usernameOne at a
        secondLetter = usernameTwo[a]; //second Letter equals usernameTwo at a
        if(firstLetter==secondLetter || firstLetter == (secondLetter + 32) || firstLetter == (secondLetter- 32)) //If the letters have the same character # in the ASCII table or are 32 apart:
        {
            sameLetter++; //Add one to same letter
        }
        
    }
    if(sameLetter==usernameOne.length()) //If every character between the two strings are the same:
    {
        return true; //Return true
    }
    return false; //Return false
}

int main()
{
    string playAgainChoice; 
    bool playAgain = false;
    char buyKnights = ' ';
    string name = "";
    int money=0;
    ifstream myFile;
    int influence=0;
    int armySize=0;
    int row=0;
    int column=0;
    string pointsTile;
    int heroChoice;
    char yOrN;
    int turnNumber=1;
    Hero player;
    string tile;
    int turnChoice;
    int lineNum =0;
    bool stillPlaying= true;
    int warriorCount=0;
    int cityLocation;
    int direction;
    char rumors;
    Map map;
    string store[11];
    Hero heroes[7];
     map.setMap();
    string store2[7];
    string warriors1[4];
    int numKnights;
    Warrior warriors[14];
    int warriorIndex=0;
    myFile.open("warriorsGOT.txt");
            if (myFile.is_open()) //If file opens:
            {
                string line2 = ""; //Line equals ""
        
        
                while (getline(myFile, line2))  //For every line in the file:
                {
                    
                     if(!line2.empty()) //If line isn't empty:
                         {
                                split(line2,',',store2,7); //Store in store arrau
                                warriors[warriorIndex].setWarriorName(store2[0]); //Store first string in warrior name 
                                warriors[warriorIndex].setWarriorStrength(stoi(store2[1])); //Store Warrior Strength
                                warriors[warriorIndex].setWarriorLoyalty(stoi(store2[2])); //Store Warrior Loyalty[]
                                warriors[warriorIndex].setWarriorMorale(stoi(store2[3])); //Store Warrior Morale
                                warriors[warriorIndex].setWarriorFree(store2[4]); //Set warrior free or not
                                warriors[warriorIndex].setWarriorShip(store2[5]); //Set Warrior Ship
                                warriors[warriorIndex].setWarriorDragonlass(store2[6]); //Set Warrior Dragonglass
                                for(int v=0; v<7;v++) 
                                {
                                    store2[v] = ""; //Clear store array
                                }
                         }
                            warriorIndex++; //Go to next warrior
                    } 
                    
                    
                }
    myFile.close(); //Close File
    myFile.open("heroesGOT.txt"); //Open hero file
            if (myFile.is_open()) //If file opens:
            {
                string line = ""; //Line equals ""
        
        
                while (getline(myFile, line))  //For every line in the file:
                {
                    
                     if(!line.empty()) //If line isn't empty:
                         {
                                split(line,',',store,11); //Split hero stats
                                heroes[lineNum].setHeroName(store[0]); //Store hero name
                                heroes[lineNum].setHeroMoney(stoi(store[1])); //Set hero Money
                                heroes[lineNum].setHeroInfluence(stoi(store[2])); //Set hero Influence
                                heroes[lineNum].setArmySize(stoi(store[3]));  //Set army size
                                for(int i=0; i<4;i++) //For every warrior
                                {
                                    warriors1[i] = store[i+4]; //Store Warrior 
                                }
                                heroes[lineNum].setWarriors(warriors1); //Store warrior in hero
                                heroes[lineNum].setHeroLocation(stoi(store[8])-1,stoi(store[9])-1); //Store Hero Location
                                heroes[lineNum].setShip(store[10]); //Store ship
                                for(int y=0; y<11;y++){ 
                                    store[y] = ""; //Clear store array
                                    }
                            }
                            lineNum++; //Add one to line
                        } 
                    
                    
                }
                myFile.close();
        string store3[5]; //Create third store array
        int index1; //Integer index
        City cities[26]; //Create cities array
        myFile.open("citiesGOT.txt");
            if (myFile.is_open()) //If file opens:
            {
                string line3 = ""; //Line equals ""
        
        
                while (getline(myFile, line3))  //For every line in the file:
                {
                    
                     if(!line3.empty()) //If line isn't empty:
                         {
                             split(line3,',',store3,5); //Split city stats
                             cities[index1].setLetter(store3[0]); //Store letter
                             cities[index1].setCityName(store3[1]); //Store name
                             cities[index1].setCityMoney(stoi(store3[2])); //Store city money
                             cities[index1].setCityArmySize(stoi(store3[3])); //Set city army
                             cities[index1].setCityPoints(stoi(store3[4])); //Set city points
                             for(int v=0; v<5;v++){
                                    store3[v] = ""; //Clear store array
                                    }
                         }
                    index1++; //Add one to index
                }
            }
            myFile.close(); //Close file
            heroes[1].setShip("yes");
    while(!playAgain){
    turnNumber=1; //Set turn number equal to 1
    cout<< "Welcome to the G A M E of T H R O N E S!" <<endl;
    cout<< "State your name, Your Grace: "; //Game menu
    cin>> name; //Store user name
    cout<< "Would you like to choose a hero " << name<< ", Your Grace?(Y/N): "; 
    cin>> yOrN; //Store user chocie
    cout<<endl; 
    switch (yOrN){ //Switch input
        case 'y':
        case 'Y': //If user answers yes,
            cout<< "Please choose from the following heroes:"<<endl;  //Output all heroes
            cout<<endl;
            cout << "1. Cersei Lannister"<<endl;
            cout << "2. Stannis Baratheon"<<endl;
            cout << "3. Jon Snow"<<endl;
            cout << "4. Sansa Stark"<<endl;
            cout << "5. Euron Greyjoy"<<endl;
            cout << "6. Daenerys Targaryen"<<endl;
            cout<< endl;
            cout<< "Choice(1-6): "; //Ask user to choose hero
            cin>>heroChoice; //Store hero choice
            heroChoice--; //Subtract one from hero choice for array
            
            myFile.close(); //CLose file
            cout<< endl;
            cout<< "You have chosen, " << heroes[heroChoice].getHeroName() << "." <<endl; //Output user choice
            cout<< heroes[heroChoice].getHeroName() << "'s Stats"<<endl; //Show user stats
            cout<< "-------------------------------"<<endl;
            cout<< "Money: " << heroes[heroChoice].getHeroMoney()<<endl; //SHow user money
            cout<< "Influence: " << heroes[heroChoice].getHeroInfluence()<<endl; //Show user influence
            cout<< "Army Size: " << heroes[heroChoice].getArmySize()<<endl; //Show user army
            cout<< "Warriors: "; //Show user's warriors
            for (int f=0; f<4;f++){ //For every warrior inside the heroes
                
                cout<< heroes[heroChoice].getWarriors(f).getWarriorName(); //Print Hero's warriors
                if(f!=3){ 
                    cout<< ", "; //Print comma in between each
                }
                else{
                cout<<endl;
                }
            }
            cout<< "Ship: " << heroes[heroChoice].getShip()<<endl; //Print if user has shsip
            
        break;
        case 'n':
        case 'N': //If user answers no:
        
            cout<< "Your Grace " << name<< ", you have chosen to go on this journey alone." <<endl; //Print user chocie
            cout<< "Please provide starting values for your adventure." <<endl;
            cout<< endl;
            cout<<"Please enter your money (between 0 and 10000): "<<endl; //Ask user for money choice
            cin>> money;
            cout<<"Please enter your influence (between 0 and 10000): "<<endl; //Have user choose influence
            cin>> influence;
            cout<<"Please enter your army size (between 0 and 10000): "<<endl; //Have user choose army size
            cin>> armySize;

            cout<<"Please enter your the row of your starting location (between 1 and 25): "<<endl; //Choose user row
            cin>> row;
            cout<<"Please enter your the column of your starting location (between 1 and 16): "<<endl; //Have user choose column
            cin>> column;
            
            heroChoice =6; //Hero choice is 6
            for(int r=0; r<4;r++){
                    warriors1[r] = "NULL"; //Set warrior names to Null
            }
            heroes[heroChoice].setWarriors(warriors1); //Set Warriors
            heroes[heroChoice].setHeroName(name); //Set name
            heroes[heroChoice].setHeroMoney(money); //Set money
            heroes[heroChoice].setHeroInfluence(influence); //Set influence
            heroes[heroChoice].setArmySize(armySize);  //Set army size
            heroes[heroChoice].setHeroLocation(row-1, column-1); //Set location
            tile = map.getTile(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn()); //get tile
            
            if(tile == "w") //Check if tile is water
            {
                heroes[heroChoice].setShip("yes"); //Ship is yes
            }
            
        break;
        default:
        break;
    }
    cout<<endl;

    bool directionWorks=false; //Create boolean
    string whiteWalkerChoice; //Create string
    string ship; //Creat ship variable
    bool payRespects= false; //Set boolean
    char respects=' '; //Set char
    int turnPoints; //Create int for points
    while(stillPlaying){ //While user is alive:
        whiteWalkerChoice="";  //Set string to blank
        cout<< endl;
        if(turnNumber==10){ //If turn number 10:
            if(heroChoice == 1){ //If ehro choice is 1:
                cout<< "OH NO! Stanis has been consumed by his demons" <<endl;
                cout<< "Unfortunately, you have lost." <<endl; //User dies
                stillPlaying == false;
                break;
            }
            else{
                cout <<"Stannis has retired. Press F to pay respects." <<endl; //Stanis dies
                cin>> respects;
                if(respects!=' '){
                    payRespects= true;
                }
                while(payRespects){
                    switch(respects){
                        case 'f':
                        case 'F':
                        cout<< "Mood."<< endl;
                        payRespects = false;
                        break;
                        default:
                        cout<< "Have you no respect?! Press F to pay respects." <<endl; //Ask user to pay resepects
                        cin >> respects;
                        break;
                    }
                }
            }
        }
        if(turnNumber>=51) //If turn number is greater than 50
        {
            cout<< "Sad news! The White Walkers are approaching our location. Would you like to battle them now? (Y/N): "<<endl; //Ask user if they want to fight
            cin >> whiteWalkerChoice;
        }
        cout<< "TURN NUMBER " << turnNumber<< endl; //Print turn number
        cout<< endl;
        cout<< "--------MAP--------" <<endl;
        map.getMap(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn());
        cout<< endl;
        cout << heroes[heroChoice].getHeroName() << "'s Current Stats" <<endl;
            cout<< "-------------------------------"<<endl;
            cout<< "Money: " << heroes[heroChoice].getHeroMoney()<<endl; //Print user money
            cout<< "Influence: " << heroes[heroChoice].getHeroInfluence()<<endl; //Print user influence
            cout<< "Army Size: " << heroes[heroChoice].getArmySize()<<endl; //Print user hero army
            cout<< "Warriors: ";
            for (int f=0; f<4;f++){
                
                cout<< heroes[heroChoice].getWarriors(f).getWarriorName(); //Print hero warriors
                if(f!=3){
                    cout<< ", ";
                }
                else{
                cout<<endl;
                }
            }
            cout<< "Ship: " << heroes[heroChoice].getShip()<<endl; //Print ship
            cout<< heroes[heroChoice].getHeroName() <<"'s Total Points: " << heroes[heroChoice].getHeroPoints() <<endl;
            cout<< endl;
        cout<< "Do you want to Travel(1), Rest(2), or Consult with The Gods(3)?"<<endl; //Ask user what they want to do
        cin>> turnChoice;
        switch(turnChoice){
            case 1: //If user travels:
                directionWorks= false;
                while(!directionWorks) //Repeat until direction is valid
                {
                    cout<<endl;
                    cout<< "Do you want to travel North(1), East(2), South(3), or West(4)" <<endl; //Ask which direction to travel
                    cin >>direction;
                    if(direction==1){ //If north:
                        
                        if(heroes[heroChoice].getPositionRow()-1 < 0){ //Check out of bounds
                            cout<< "You are moving out of the map, please pick another direction." <<endl;
                            directionWorks = false;
                        }
                        else{ //Else:
                            tile = map.getTile((heroes[heroChoice].getPositionRow()-1), heroes[heroChoice].getPositionColumn()); //Get tile
                        
                            if(tile == "w"){ //If its water:
                                ship = heroes[heroChoice].getShip(); //Get ship
                                if(ship == "yes" || ship == "Yes"){ //If they have ship:
                                    heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow()-1, heroes[heroChoice].getPositionColumn()); //Travel
                                    directionWorks = true; //Exit Loop
                                }
                                
                                else{ //Else:
                                    cout<< "You are unable to travel on water without a ship, please pick a direction again." <<endl; //Dont travel
                                    directionWorks = false;
                                }
                            }
                        
                        else{
                            heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow()-1, heroes[heroChoice].getPositionColumn()); //Move hero
                            directionWorks = true;
                        }
                        }
                    }
                    else if(direction==2){ //If east:
                        
                        
                        if(heroes[heroChoice].getPositionColumn()+1 > 15){ //If out of bounds:
                            cout<< "You are moving out of the map, please pick another direction." <<endl; //Ask user to choose again
                            directionWorks = false;
                        }
                        else{ //Else:
                            tile = map.getTile((heroes[heroChoice].getPositionRow()), heroes[heroChoice].getPositionColumn()+1);
                        
                            if(tile == "w"){ //If tile is water:
                            ship = heroes[heroChoice].getShip(); //Get ship
                            if(ship == "yes" || ship == "Yes"){ //If ship:
                                heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn()+1); //Travel
                                directionWorks = true;
                            }
                            
                            else{ //Else:
                                cout<< "You are unable to travel on water without a ship, please pick a direction again." <<endl; //Repick location
                                directionWorks = false;
                            }
                        
                        }
                        else{ //Else:
                            heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn()+1); //Move hero
                            directionWorks = true;
                        }
                        }
                    }
                    else if(direction==3){ //If south:
                        
                        if(heroes[heroChoice].getPositionRow()+1 > 24){ //Check if out of bounds
                            cout<< "You are moving out of the map, please pick another direction." <<endl; //Ask them to ask again
                            directionWorks = false;
                        }
                        else{ //Else:
                            tile = map.getTile((heroes[heroChoice].getPositionRow()+1), heroes[heroChoice].getPositionColumn()); //Get tile
                        
                        if(tile == "w"){ //If water:
                            ship = heroes[heroChoice].getShip(); //Get ship
                            if(ship == "yes" || ship == "Yes"){ //If ship:
                                heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow()+1, heroes[heroChoice].getPositionColumn()); //Move hero
                                directionWorks = true;
                            }
                            else{ //Else:
                                cout<< "You are unable to travel on water without a ship, please pick a direction again." <<endl; //Ask user to choose again
                                directionWorks = false;
                            }
                        
                        }
                        else{ //Else:
                            heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow()+1, heroes[heroChoice].getPositionColumn()); //Move hero
                            directionWorks = true;
                        }
                        }
                    }
                    else if(direction==4){ //If west:
                        
                        if(heroes[heroChoice].getPositionColumn()-1 < 0){ //If out of bounds:
                            cout<< "You are moving out of the map, please pick another direction." <<endl; //Pick again
                            directionWorks = false;
                        }
                        else{ //Else
                            tile = map.getTile((heroes[heroChoice].getPositionRow()), heroes[heroChoice].getPositionColumn()-1); //Get tile
                        
                            if(tile == "w"){ //Check if water:
                            ship = heroes[heroChoice].getShip(); //Get ship
                            if(ship == "yes" || ship == "Yes"){ //If ship:
                                heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn()-1); //Move hero
                                directionWorks = true;
                            }
                            else{ //Else:
                                cout<< "You are unable to travel on water without a ship, please pick a direction again." <<endl; //Pick again
                                directionWorks = false;
                            }
                        }
                        
                        else{ //Else:
                            heroes[heroChoice].setHeroLocation(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn()-1);//Move hero
                            directionWorks = true;
                        }
                        }
                    }
                    
                }
                pointsTile =map.getTile(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn()); //Get points tile
                if(pointsTile=="p"){ //If land:
                        turnPoints = heroes[heroChoice].getHeroPoints() + 2; //Add 2 points
                        heroes[heroChoice].setHeroPoints(turnPoints); //Set points
                }
               
                else if(pointsTile == "w"){ //If water
                    
        
                        turnPoints = heroes[heroChoice].getHeroPoints() + 1; //Add 1 point
                        heroes[heroChoice].setHeroPoints(turnPoints); //Set points
                }
                else{ //Else:
                    for(int g=0; g<26;g++){ 
                        if(pointsTile == cities[g].getLetter()){ //If city matches:
                            cityLocation = g; //Story city location
                            break; //Break
                        }
                    }
                        turnPoints = heroes[heroChoice].getHeroPoints() + cities[cityLocation].getCityPoints(); //Get city points
                        if(cities[cityLocation].getCityMoney() != 0){ //If city has monney:
                            cout<< "You got " << cities[cityLocation].getCityMoney() << " gold for controlling " << cities[cityLocation].getCityName()<<endl; //Print money
                        }
                        heroes[heroChoice].setHeroMoney(heroes[heroChoice].getHeroMoney() + cities[cityLocation].getCityMoney()); //Set hero money
                        cities[cityLocation].setCityMoney(0); //Set hero money to 0
                        heroes[heroChoice].setHeroPoints(turnPoints); //Set hero points
                        cout<< "You have arrived in "<< cities[cityLocation].getCityName() <<". Do you want to listen to rumours? Y/N: " <<endl; //Ask user to listen to rumors
                            cin >> rumors;
                            switch(rumors){
                                case 'Y': //If yes:
                                    
                                break;
                                case 'N': //If no:
                                break;
                                default:
                                break;
                            }
                       cout<< "You currently have a balance of " << heroes[heroChoice].getHeroMoney()<<endl; //Print balance
                       cout << cities[cityLocation].getCityName()<< " has " << cities[cityLocation].getCityArmySize() << " knights. Do you want to buy more knights? Y/N: "<<endl; //Ask user if they want knights
                       cin >> buyKnights;
                       switch(buyKnights){
                                case 'Y':
                                    cout<< "How many knights do you want? (20 Gold Per Knight)" <<endl;
                                    cin >> numKnights;
                                    if(20*numKnights > heroes[heroChoice].getHeroMoney()){
                                        cout<< "Insufficient Funds" <<endl;
                                    }
                                    else{
                                        cities[cityLocation].setCityArmySize(cities[cityLocation].getCityArmySize()-numKnights);
                                         heroes[heroChoice].setArmySize(heroes[heroChoice].getArmySize()+numKnights);
                                         heroes[heroChoice].setHeroMoney(heroes[heroChoice].getHeroMoney()-(20*numKnights));
                                        cout<< "Your new army size is " << heroes[heroChoice].getArmySize() <<endl;
                                        cout<< "Your new balance is " << heroes[heroChoice].getHeroMoney() << endl;
                                    }
                                break;
                                case 'N':
                                break;
                                default:
                                break;
                       }
                }

                cout<<endl;
            break;
            case 2:
                for(int u=0; u<4;u++){
                    if(heroes[heroChoice].getWarriors(u).getWarriorName()!="NULL"){
                        warriorCount++;
                    }
                }
                if(warriorCount==0){
                    cout<< "You have zero warriors. No one gained strength." <<endl;
                    break;
                }
                cout<< "You have chosen to rest, all your warriors have gained strength"<< endl;
                for(int t=0; t<4;t++){
                    if(heroes[heroChoice].getWarriors(t).getWarriorName()!="NULL"){
                        Warrior storage;
                        storage = heroes[heroChoice].getWarriors(t);
                        storage.setWarriorStrength(heroes[heroChoice].getWarriors(t).getWarriorStrength() + 1);
                        heroes[heroChoice].setWarriorStats(t,storage); 
                        cout<< heroes[heroChoice].getWarriors(t).getWarriorName() << " now has a strength of " << heroes[heroChoice].getWarriors(t).getWarriorStrength()<<endl;
                        
                        
                    }
                }
            break;
            case 3:
            for(int d=0; d<4;d++){
                    if(heroes[heroChoice].getWarriors(d).getWarriorName()!="NULL"){
                        warriorCount++;
                    }
                }
                if(warriorCount==0){
                    cout<< "You have zero warriors. No one gained morale." <<endl;
                    break;
                }
            cout<< "You have chosen to consult with the gods, all your warriors have gained morale"<< endl;
                for(int e=0; e<4;e++){
                    if(heroes[heroChoice].getWarriors(e).getWarriorName()!="NULL"){
                        Warrior storage1;
                        storage1 = heroes[heroChoice].getWarriors(e);
                        storage1.setWarriorMorale(heroes[heroChoice].getWarriors(e).getWarriorMorale() + 1);
                        heroes[heroChoice].setWarriorStats(e,storage1); 
                        cout<< heroes[heroChoice].getWarriors(e).getWarriorName() << " now has a morale of " << heroes[heroChoice].getWarriors(e).getWarriorMorale()<<endl;
                        
                    }
                }
            break;
            default:
            break;
        }
        int encounterChoice;
        double buyProb=0;
        double speechProb=0;
        double morale= 1.0;
        double influence = 1.0;
        double loyalty =1.0;
        double heroMoney=1.0;
        int computerWarriorCount=0;
        double strength = 1.0;
        for(int q=0; q<6; q++){
            if(encounter(heroes[heroChoice].getPositionRow(), heroes[heroChoice].getPositionColumn(), heroes[q].getPositionRow(),heroes[q].getPositionColumn()) && q!=heroChoice){
                cout<<"*WARNING*"<<endl;
                cout<< "You have encountered " << heroes[q].getHeroName()<<endl;
                cout<< "Do you want to Give a Speech(1), Buy Them Outright(2), or Battle(3)? ";
                cin>> encounterChoice;
                switch(encounterChoice){
                    case 1:
                        morale = heroes[q].getWarriors(0).getWarriorMorale()* morale;
                        influence = influence * heroes[heroChoice].getHeroInfluence();
                        speechProb= (1-((morale/100))) * (influence/1600);
                        speechProb = speechProb *100;
                        cout<< "Probability: " <<speechProb<< "% of winnning" << endl;
                        cout<< endl;
                        if(randomProb(speechProb)){
                            cout<< "Your speech has persuaded " << heroes[q].getHeroName()<< endl;
                            cout<< heroes[q].getHeroName()<< " has retired." <<endl;
                            heroes[heroChoice].setHeroMoney(heroes[q].getHeroMoney()+heroes[heroChoice].getHeroMoney());
                            heroes[heroChoice].setHeroInfluence(heroes[q].getHeroInfluence()+heroes[heroChoice].getHeroInfluence());
                            heroes[heroChoice].setArmySize(heroes[q].getArmySize()+ heroes[heroChoice].getArmySize());
                            heroes[q].setHeroMoney(0);
                            heroes[q].setHeroInfluence(0);
                            heroes[q].setArmySize(0);
                            cout<< "Your now have " << heroes[heroChoice].getHeroMoney() << " gold."<<endl;
                            cout<< "Your army now has a size of " << heroes[heroChoice].getArmySize() <<endl;
                            cout<< "You now have an influence level of " << heroes[heroChoice].getHeroInfluence() <<endl;
                            for(int d=0; d<4;d++)
                            {
                                if(heroes[heroChoice].getWarriors(d).getWarriorName()!="NULL")
                                {
                                    warriorCount++;
                                }
                                if(heroes[q].getWarriors(d).getWarriorName()!="NULL"){
                                    computerWarriorCount++;
                                }
                            }
                            if(warriorCount + computerWarriorCount >4){
                                //Let user choose warriors
                            }
                            else{
                                //Give warriors to hero user
                            }
                        }
                        else{
                            cout<<"Your speech was unsucessful and you have lost half your influence" <<endl;
                            cout<< "Fortunately, you have fled sucessfully." <<endl;
                            heroes[heroChoice].setHeroInfluence(heroes[heroChoice].getHeroInfluence()/2);
                            cout<< "Your new influence is " << heroes[heroChoice].getHeroInfluence();
                            cout<<endl;
                        }
                    break;
                    case 2:
                        loyalty=1.0;
                        loyalty = heroes[q].getWarriors(0).getWarriorLoyalty()* loyalty;
                        heroMoney = heroMoney * heroes[heroChoice].getHeroMoney();
                        buyProb= (1-((loyalty/100))) * (heroMoney/17800);
                        buyProb = buyProb *100;
                        cout<< "Probability: " <<buyProb<< "% of winnning" << endl;
                        cout<< endl;
                        if(randomProb(buyProb)){
                            //User Won
                        }
                        else{
                            cout<<"You were unable to buy out the other hero and you have lost half your gold" <<endl;
                            cout<< "Fortunately, you have fled sucessfully." <<endl;
                            heroes[heroChoice].setHeroMoney(heroes[heroChoice].getHeroMoney()/2);
                            cout<< "Your now have " << heroes[heroChoice].getHeroMoney() << " gold.";
                            cout<<endl;
                        }
                    break;
                    case 3:
                    break;
                    default:
                    break;
                }
            }
        }
        cout<<endl;
        srand(time(NULL));
        int computerDirection = 0;
        bool directionWorks1;
        cout<<"Generating moves for other Heros...." <<endl;
        cout<< endl;
      for(int k=0;k<6;k++){
          if(k!=heroChoice){
              directionWorks1 = false;
              cout<< heroes[k].getHeroName()<< " is moving."<<endl;
              
              computerDirection = 0;
              while(!directionWorks1){
                  computerDirection = randomNum();
                  if(computerDirection==1){
                      if(heroes[k].getPositionRow()-1 < 0){
                            directionWorks1 = false;
                        }
                        else{
                            tile = map.getTile((heroes[k].getPositionRow()-1), heroes[k].getPositionColumn());
                        
                            if(tile == "w"){
                                
                                ship = heroes[k].getShip();
                                if(ship == "yes" || ship == "Yes"){
                                    heroes[k].setHeroLocation(heroes[k].getPositionRow()-1, heroes[k].getPositionColumn());
                                    directionWorks1 = true;
                                }
                                
                                else{
                                    directionWorks1 = false;
                                }
                            }
                        
                        else{
                            heroes[k].setHeroLocation(heroes[k].getPositionRow()-1, heroes[k].getPositionColumn());
                            directionWorks1 = true;
                        }
                        }
                  }
                  else if(computerDirection==2){
                      if(heroes[k].getPositionColumn()+1 > 15){
                            directionWorks1 = false;
                        }
                        else{
                            tile = map.getTile((heroes[k].getPositionRow()), heroes[k].getPositionColumn()+1);
                        
                            if(tile == "w"){
                            ship = heroes[k].getShip();
                            if(ship == "yes" || ship == "Yes"){
                                heroes[k].setHeroLocation(heroes[k].getPositionRow(), heroes[k].getPositionColumn()+1);
                                directionWorks1 = true;
                            }
                            
                            else{
                                directionWorks1 = false;
                            }
                        
                        }
                        else{
                            heroes[k].setHeroLocation(heroes[k].getPositionRow(), heroes[k].getPositionColumn()+1);
                            directionWorks1 = true;
                        }
                        }
                  }
                  else if(computerDirection==3){
                      if(heroes[k].getPositionRow()+1 > 24){
                            directionWorks1 = false;
                        }
                        else{
                            tile = map.getTile((heroes[k].getPositionRow()+1), heroes[k].getPositionColumn());
                        
                            if(tile == "w"){
                                ship = heroes[k].getShip();
                                if(ship == "yes" || ship == "Yes"){
                                    heroes[k].setHeroLocation(heroes[k].getPositionRow()+1, heroes[k].getPositionColumn());
                                    directionWorks1 = true;
                                }
                                
                                else{
                                    directionWorks1 = false;
                                }
                            }
                        
                        else{
                            heroes[k].setHeroLocation(heroes[k].getPositionRow()+1, heroes[k].getPositionColumn());
                            directionWorks1 = true;
                        }
                        }
                  }
                  else if(computerDirection==4){
                      if(heroes[k].getPositionColumn()-1 < 0){
                            directionWorks1 = false;
                        }
                        else{
                            tile = map.getTile((heroes[k].getPositionRow()), heroes[k].getPositionColumn()-1);
                        
                            if(tile == "w"){
                            ship = heroes[k].getShip();
                            if(ship == "yes" || ship == "Yes"){
                                heroes[k].setHeroLocation(heroes[k].getPositionRow(), heroes[k].getPositionColumn()-1);
                                directionWorks1 = true;
                            }
                            
                            else{
                                directionWorks1 = false;
                            }
                        
                        }
                        else{
                            heroes[k].setHeroLocation(heroes[k].getPositionRow(), heroes[k].getPositionColumn()-1);
                            directionWorks1 = true;
                        }
                        }
                  }
                
              }
          map.getMap(heroes[k].getPositionRow(), heroes[k].getPositionColumn());
          }
      }
      turnNumber++;
    }
        cout<< endl;
        cout<< "Do you want to play again? (Y/N) " <<endl;
        cin >> playAgainChoice;
        if(playAgainChoice== "N"){
            playAgain = true;
        }
        else{
            cout<< "--------NEW GAME--------" <<endl;
            playAgain = false;
        }
    }
}