#include "game.h"


void game::makeTurn()
{
    //stuff
}
string game::guessWord()
{
    string guessword;
    getline(cin, guessword);
    return guessword;
	// hi
}
bool game::checkWord(string guessword)
{
    string gameword; // We need to input here the active word of the game
    if (gameword == guessword)
        return true;
    else return false;
}
char game::guessLetter()
{
    char guessletter;
    cin >> guessletter;
    return guessletter;
    
}
bool game::checkLetter(string word, char guessletter)
{
    int found = word.find(guessletter);
    if (found > 0)
        return true;
    return false;
    // This only checks IF the letter is in the word. We're going to need something to return the locations of all instances of that particular letter, and then outputs to the user where that letter is in the word. We can write another function to do so, and then call it from this function, I think, as that would make it so we don't have to run that function if the letter isn't in the word at all.
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
void game::findLetterPos(string word, string found)
{

}