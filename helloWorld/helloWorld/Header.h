
#include <iostream>
#include <string>

#ifndef helloWorld_Header_h
#define helloWorld_Header_h


using namespace std;


class game{
private:
    string name;
    int wins;
    int losses;
    int timesPlayed;
    
public:
    string getName(){
        return name;
    }
    int getWins(){
        return wins;
    }
    int getLosses(){
        return losses;
    }
    double getAverage(){
        return wins / (wins + losses);
    }
    int getTimesPlayed(){
        return timesPlayed;
    }
    void setName(string _name){
        name = _name;
    }
    
    
};


#endif
