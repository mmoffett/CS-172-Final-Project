
#include <iostream>
#include <string>

#ifndef hangman_player_h
#define hangman_player_h


using namespace std;


class player
{
private:
    string name;
    int wins;
    int losses;
    int timesPlayed;
    
public:
    string getName();
    int getWins();
    int getLosses();
    double getAverage();
    int getTimesPlayed();
    void setName(string _name);
};



#endif
