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
    string current(int n);
    void checkLetter(char guessletter);
    bool checkWord(string guessword);
    
public:
    bool makeTurn();
    string guessWord();
	void chooseWord(ifstream& fin);
    char guessLetter();
    char chooseCategory();
    void openFile();
    void updatePlayers(bool win, int winner);
    void saveScores();
	bool winGame();
	void findLetterPos(char guessletter);
	void addPlayer(player p);
	player getPlayer(int pos);
	player createPlayer();
	void play();
    
};

#endif
