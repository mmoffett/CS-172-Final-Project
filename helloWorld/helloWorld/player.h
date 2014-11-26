
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
	player(string _name);
	player(string _name, int _wins, int _losses, int _timesPlayed);
    string getName();
    int getWins();
    int getLosses();
    double getAverage();
    int getTimesPlayed();
    void setName(string _name);
	void upWins();
	void upLosses();
	void upTimesPlayed();
};



#endif
