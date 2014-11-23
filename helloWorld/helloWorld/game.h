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
    
public:
    void makeTurn();
    string guessWord();
    bool checkWord(string guessword);
    char guessLetter();
    bool checkLetter(string word, char guessletter);
    void chooseCategory();
    void openFile();
    void updatePlayers();
    void saveScores();
    
    
};

#endif
