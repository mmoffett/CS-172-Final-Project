#include "game.h"

/*
* Adds a player to the vector players.
*
* @param  p		player we are adding to the players vector
*/
void game::addPlayer(player p)
{
	players.push_back(p);
}

/*
* Completes one turn in the running of the game.
*
*@ return		if the guess that the player made during this turn was correct(true) or not(false)
*/
bool game::makeTurn()
{
	bool gamewon = false;

	cout << " would you like to guess the word? (y/n)" << endl;
	char k;
	cin >> k;
	if (k == 'y' || k == 'Y')
		return checkWord(guessWord());
	char guessletter = guessLetter();
	checkLetter(guessletter);
	for (int i = 0; i<_found.size(); i++)
		cout << current(i) << " ";
	cout << "\n";
	return (_found.find(guessletter) != -1);
}

/*
* Checks if the game game is won by looking at if there are unguessed letters left.
*
* @return     if there are still unguessed letters(false) or not(true)
*/
bool game::winGame()
{
	bool gamewon = false;
	if (_found.find('_') == -1)
	{
		gamewon = true;
	}

	return gamewon;
}

/*
* Gets user input for their guess word.
*
* @return     the user's guess
*/
string game::guessWord()
{
    string guessword;
	cout << "What word would you like to guess?" << endl;
	cin >> guessword;
    return guessword;
}

/*
* Finds the current letter representation at position in the _found string.
*
* @param  n		what position to check at
* @return     the string of this one letter
*/
string game::current(int n)
{
    return _found.substr(n,1);
}

/*
* Checks if the word the user guessed is the hangman word.
*
* @param  guessword		the user's guess
* @return     if the word is the word
*/
bool game::checkWord(string guessword)
{
	if (word == guessword)
	{
		_found = word;
		return true;
	}
    else 
		return false;
}

/*
* Gets user's input for their guess letter.
*
* @return     the char letter they guess
*/
char game::guessLetter()
{
    cout << "enter a letter: ";
    char guessletter;
    cin >> guessletter;
    return guessletter;  
}

/*
* Checks if the letter the user guessed is in the hangman word and if it is, calls the findLetterPos function.
*
* @param  guessletter	the user's guess
*/
void game::checkLetter(char guessletter)
{
	if (word.find(guessletter) != -1)
	{
        findLetterPos(guessletter);
	}
}

/*
* Asks the user to choose the catagory.
*
* @return     the char number of which category the user chooses
*/
char game::chooseCategory()
{
    char category;
    cout << "Choose a category: \n 1) Christmas \n 2) Trick Words \n 3) Animals \n 4) Harry Potter \n enter a number only:";
    cin >> category;
	return category;
}

/*
* Opens the file for the category of words.
*/
void game::openFile()
{
	ifstream fin;
	char category = 0;
	while (category != '1' && category != '2' && category != '3'&& category != '4')
	{
		category = chooseCategory();
	}
	string filename;

	if (category == '1')//comment out hardcoding when not using Hannah's computer
		filename = "/Users/hannahcobb/Desktop/School/2014.3Fall/ComputerScience2/CS-172-Final-Project/helloWorld/helloWorld/Christmas.txt";
	//filename="Christmas.txt";
	else if (category == '2')
		filename = "/Users/hannahcobb/Desktop/School/2014.3Fall/ComputerScience2/CS-172-Final-Project/helloWorld/helloWorld/TrickWords.txt";
	//filename="TrickWords.txt";
	else if (category == '3')
		filename = "/Users/hannahcobb/Desktop/School/2014.3Fall/ComputerScience2/CS-172-Final-Project/helloWorld/helloWorld/Animals.txt";
	//filename="Animals.txt";
	else if (category == '4')
		filename = "/Users/hannahcobb/Desktop/School/2014.3Fall/ComputerScience2/CS-172-Final-Project/helloWorld/helloWorld/HarryPotter.txt";
	//filename="HarryPotter.txt";
	fin.open(filename);
	if (!fin)
	{
		cout << "can't open file" << endl;
        // We should have something here that ends the program if the file can't be opened.
        return;
	}
	chooseWord(fin);
	cout << "Your word:";
	for (int i = 0; i < _found.size();i++)
		cout<< current(i)<<" ";
	cout << endl;
	fin.close();
}

/*
* Update's the player's wins/losses/timesPlayed.
*
* @param  won	if the game was won
* @param winner	if so, who won
*/
void game::updatePlayers(bool won, int winner)
{
	for (int i = 0; i < players.size(); i++)
	{
		players.at(i).upTimesPlayed();
		if (won == true)
		{
			if (i == winner)
				players.at(i).upWins();
			else
				players.at(i).upLosses();
		}
    }
}

/*
* Finds the position the letter is at in the word and puts that letter into _found.
*
* @param  guessLetter	the letter to enter
*/
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

/*
* Chooses the word for the game.
*
* @param  fin	the file stream that the word is read from
*/
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
    for (int i = 1; i < word.length(); i++)
	{
		_found += "_";
	}
}

/*
* Updates the user's statistics in the ongoing file or creates a new file for the user.
*/
void game::saveScores()
{
	ofstream fout;
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
			fout << "Information for Newest Data: Player Name, Wins, Losses, Times Played, Average\n";
            fout << temp.getName()<<endl;
            fout << temp.getWins() << endl;
            fout << temp.getLosses() << endl;
            fout << temp.getTimesPlayed() << endl;
            fout << temp.getAverage() << endl;
            fout.close();
        }
}

/*
* Returns the player at a given position
*
* @param  pos  which player in the vector
* @return     the player
*/
player game::getPlayer(int pos)
{
	return players[pos];
}

/*
* Adds a player to the player vector after reading any existing file for the player's stats.
* @return     the player that was just made
*/
player game::createPlayer()
{
	ifstream fin;
	cout << "Enter player name" << endl;
	string name;
	cin >> name;
	string filename = name;
	filename += ".txt";
	fin.open(filename);
	player nextPlayer=(*new player(name));//makes empty player with name
	if (fin.fail())
	{
		cout << "Welcome, new player, "<< name<<"! \nYou currently have 0 wins, 0 losses, and no games played" << endl;
	}
	else
	{
		string random;
		getline(fin, random);//this is the intro line
		getline(fin, random);//this is the name which we already have
		string num;
		getline(fin, num);
		int win = atoi(num.c_str());
		getline(fin, num);
		int loss = atoi(num.c_str());
		getline(fin, num);
		int played = atoi(num.c_str());
        nextPlayer.setWinCount(win);
        nextPlayer.setLoss(loss);
        nextPlayer.setTimesPlayed(played);
        cout << "Welcome, player, "<< name<<"! \nYou currently have "<<win<<" wins, "<<loss<<" losses, and "<<played<<" games played" << endl;
		//if file exists with this player, read it and make player
	}
	return nextPlayer;
}

/*
* Runs the entire game.
*/
void game::play()
{
	openFile();
	bool gamewon = false;
	int tries = 6;
	while (tries > 0)
	{
		for (int i = 0; i < players.size(); i++)
		{
			bool correctGuess;
			cout << getPlayer(i).getName() << ", it is your turn";
			correctGuess = makeTurn();
			gamewon = winGame();
			if (gamewon == true)
			{
				cout << "Congratulations " << getPlayer(i).getName() << ", You Won\n" << endl;
				updatePlayers(true, i);
				tries = 0;
				return;
			}
			else if (correctGuess == true)
			{
				cout << "Good Job, keep trying" << endl;
			}
			else
			{
				tries--;
				cout << "You have " << tries << " tries left" << endl;
			}
			if (tries == 0)
			{
				updatePlayers(false,-1);
			}
		}
	}
}