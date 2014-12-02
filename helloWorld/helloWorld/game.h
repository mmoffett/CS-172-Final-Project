#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#ifndef hangman_game_h
#define hangman_game_h
#include "player.h"

using namespace std;

class game
{
private:
    string word;
    vector <player> players;
    int guesses;
	string _found;
	ifstream fin;
	ofstream fout;
    
public:
    bool makeTurn(player activePlayer, player *winner);
    string guessWord();
    bool checkWord(string guessword);
	void chooseWord(ifstream& fin);
    char guessLetter();
    void checkLetter(char guessletter);
    char chooseCategory();
    void openFile();
    void updatePlayers();
    void saveScores();
	void findLetterPos(char guessletter);
	void addPlayer(player p);
	player getPlayer(int pos);
	player createPlayer();
    
};

#endif
