#include <iostream>
#include <string>

#ifndef hangman_player_h
#define hangman_player_h

class player{
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
