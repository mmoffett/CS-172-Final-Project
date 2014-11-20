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
    void guessWord();
    bool checkWord();
    void guessLetter();
    bool checkLetter();
    void chooseCategory();
    void openFile();
    void updatePlayers();
    void saveScores();
    
    
};

#endif
