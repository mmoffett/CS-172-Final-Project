#include "game.h"

void game::addPlayer(player p)
{
	players.push_back(p);
}
bool game::makeTurn(player activePlayer, player *winner)
{
    bool gamewon = false;
    
        cout << " would you like to guess the word? (y/n)" << endl;
        char k;
        cin >> k;
        if (k == 'y'||k=='Y')
           return checkWord(guessWord());
        char g=guessLetter();
        checkLetter(g);
        cout << _found;
        if (_found.find('_') == 0)
        {
            gamewon = true;
            *winner = activePlayer;
        }

    
    // If player would like to guess the word, call the guessWord and checkWord functions
    // If not, call the guessLetter and checkLetter functions
    // return (?) info on how game is progressing (e.g., what letters have been guessed correctly)
    return gamewon;
}
string game::guessWord()
{
    string guessword;
    getline(cin, guessword);
    return guessword;
}
bool game::checkWord(string guessword)
{
    if (word == guessword)
        return true;
    else 
		return false;
}
char game::guessLetter()
{
    cout << "enter a letter: ";
    char guessletter;
    cin >> guessletter;
    return guessletter;  
}
void game::checkLetter(char guessletter)
{
	if (word.find(guessletter) != -1)
	{
        findLetterPos(guessletter);
	}
    // This only checks IF the letter is in the word. We're going to need something to return the locations
    // of all instances of that particular letter, and then outputs to the user where that letter is in the word.
    // We can write another function to do so, and then call it from this function, I think, as that would make
    // it so we don't have to run that function if the letter isn't in the word at all.
}
char game::chooseCategory()
{
    char category;
    cout << "Choose a category: \n 1) Christmas \n 2) Trick Words \n 3) Animals \n enter a number only:";
    cin >> category;
	return category;
}
void game::openFile()
{
	char category;
	while (category != '1' && category != '2' && category != '3')
	{
		category = chooseCategory();
	}
	string filename;

	if (category == '1')
		filename = "Christmas.rtf";
	else if (category == '2')
		filename = "TrickWords.txt";//if want to use rtf for all of them, we need to make them on the mac since i can't
	else if (category == '3')
		filename = "Animals.txt";
	fin.open(filename);
	string fileName;
	fin.open(filename);
	if (!fin)
	{
		cout << "can't open file" << endl;
        return;
	}
	chooseWord(fin);
	fin.close();
}
void game::updatePlayers()
{
	for (int i = 0; i < players.size(); i++)
	{
		player temp = players.at(i);
		temp.upTimesPlayed();
		//if won up wins, if lost, up losses
    }
}

void game::findLetterPos(char guessLetter)
{
    for (int i = 0; i < word.length();i++)
	{
		if (word.at(i) == guessLetter)
		{
			_found.at(i) = guessLetter;
		}
	}
}
void game::chooseWord(ifstream& fin)
{
	string temp;
	srand(time(NULL));
	int x = rand() % 39;
	for (int i = 0; i < x; i++)
	{
		fin >> temp;
	}
	word = temp;
	_found = "_";
	for (int i = 1; i < word.length() << i++)
	{
		_found += "_";
	}
}
void game::saveScores()
{
        for (int i = 0; i < players.size(); i++)
        {
            player temp = players.at(i);
            string filename = temp.getName();
            filename += ".txt";
            fout.open(filename);
            if (fout.fail())
            {
                cout << "can't open file" << endl;
                return;
            }
            fout << "Player Name: " << temp.getName();
            fout << "Newest Data: " << endl;
            fout << "Wins: " << temp.getWins() << endl;
            fout << "Losses: " << temp.getLosses() << endl;
            fout << "Times Played: " << temp.getTimesPlayed() << endl;
            fout << "Average: " << temp.getAverage() << endl;
            fout.close();
        }
}
player game::getPlayer(int pos)
{
	return players[pos];
}