#include "game.h"


void game::makeTurn(player activePlayer, string activeWord)
{
	cout << " would you like to guess the word? (y/n)" << endl;
	char k;
	cin >> k;
	if (k == 'y')
		guessWord();
	checkLetter(guessLetter(), word);

    // If player would like to guess the word, call the guessWord and checkWord functions
    // If not, call the guessLetter and checkLetter functions
    // return (?) info on how game is progressing (e.g., what letters have been guessed correctly)
}
string game::guessWord()
{
    string guessword;
    getline(cin, guessword);
    return guessword;
}
bool game::checkWord(string guessword, string gameword)
{
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
void game::checkLetter(string word, char guessletter)
{
	if (word.find(guessLetter) != -1)
	{
		findLetterPos(word,found,guessLetter)
	}
    // This only checks IF the letter is in the word. We're going to need something to return the locations
    // of all instances of that particular letter, and then outputs to the user where that letter is in the word.
    // We can write another function to do so, and then call it from this function, I think, as that would make
    // it so we don't have to run that function if the letter isn't in the word at all.
}
char game::chooseCategory()
{
    char category;
    cout << "Choose a category: \n 1) Christmas \n 2) Don't choose this one \n enter a number only:";
    cin >> category;
	return category;
}
void game::openFile()
{
	char category = chooseCategory();
	string fileName;
	//if char is 1, file is___, etc
	fin.open(filename);
	if (!fin)
	{
		cout << "can't open file" << endl;
		return 0;
	}
}
void game::updatePlayers()
{
	for (int i = 0; i < players.size(); i++)
	{
		Player temp = players.at(i);
		temp.upTimesPlayed();
		//if won up wins, if lost, up losses
}
void game::saveScores()
{
	for (int i = 0; i < players.size(); i++)
	{
		Player temp = players.at(i);
		string filename = temp.getName();
		filename += ".txt";
		fout.open(filename);
		if (fout.fail())
		{
			cout << "can't open file" << endl;
			return 0;
		}
		fout << "Player Name: "temp.getName();
		fout << "Newest Data: " << endl;
		fout << "Wins: " << temp.getWins() << endl;
		fout << "Losses: " << temp.getLosses() << endl;
		fout << "Times Played: " << temp.getTimesPlayed() << endl;
		fout << "Average: " << temp.getAverage() << endl;
		fout.close();
	}
}
void game::findLetterPos(string word, string found, char guessLetter)
{
	for (int i = 0; i < word.length())
	{
		if (word.at(i) == guessLetter)
		{
			found.at(i) = guessLetter;
		}
	}
}
void game::chooseWord()
{
	//goes through file and picks one word randomly
}