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
	bool checkWord(string guessword);
	void checkLetter(char guessletter);
	string current(int n);
	void findLetterPos(char guessletter);

public:
	void addPlayer(player p);
	player getPlayer(int pos);
	player createPlayer();
	char chooseCategory();
	void openFile();
	void chooseWord(ifstream& fin);
	bool makeTurn();
	bool winGame();
	string guessWord();
	char guessLetter();
	void updatePlayers(bool win, int winner);
	void play();
	void saveScores();

};

#endif