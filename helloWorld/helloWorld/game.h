#include <iostream>
#include <string>
#include <vector>

#ifndef hangman_game_h
#define hangman_game_h
#include "player.h"
#include "Christmas.rtf"

using namespace std;

class game{
private:
    string word;
    vector <player> players;
    int guesses;
	string found;
    
public:
    void makeTurn(player activePlayer, string activeWord);
    string guessWord();
    bool checkWord(string guessword, string gameword);
    char guessLetter();
    void checkLetter(string word, char guessletter);
    char chooseCategory();
    void openFile();
    void updatePlayers();
    void saveScores();
	void findLetterPos(string word, string found);
    
    
};

#endif
