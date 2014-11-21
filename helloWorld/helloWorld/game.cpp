#include "game.h"


void game::makeTurn()
{
    //stuff
}
void game::guessWord()
{
    string guessword;
    getline(cin, word);
}
bool game::checkWord(string guessword)
{
    string gameword; // We need to input here the active word of the game
    if (gameword == guessword)
        return true;
    else return false;
}
void game::guessLetter()
{
    
}
bool game::checkLetter()
{
    return true; //FIX THIS
}
void game::chooseCategory()
{
    char category;
    cout << "Choose a category: \n 1) Christmas \n 2) Don't choose this one \n enter a number:";
    cin >> category;
    
}
void game::openFile()
{
    
}
void game::updatePlayers()
{
    
}
void game::saveScores()
{
    
}