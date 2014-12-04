#include "game.h"

void game::addPlayer(player p)
{
	players.push_back(p);
}
bool game::makeTurn()
{
    bool gamewon = false;
    
        cout << " would you like to guess the word? (y/n)" << endl;
        char k;
        cin >> k;
        if (k == 'y'||k=='Y')
           return checkWord(guessWord());
        checkLetter(guessLetter());
    for(int i=0;i<_found.size();i++)
        cout<<current(i)<<" ";
    cout<<endl;
        if (_found.find('_') == 0)
        {
            gamewon = true;
        }
    
       return gamewon;
}
string game::guessWord()
{
    string guessword;
	cout << "What word would you like to guess?" << endl;
	cin >> guessword;
    return guessword;
}
string game::current(int n)
{
    return _found.substr(n,1);
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
}
char game::chooseCategory()
{
    char category;
    cout << "Choose a category: \n 1) Christmas \n 2) Trick Words \n 3) Animals \n 4) Harry Potter \n enter a number only:";
    cin >> category;
	return category;
}
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
void game::updatePlayers(bool won, int winner)
{
	for (int i = 0; i < players.size(); i++)
	{
		player temp = players.at(i);
		temp.upTimesPlayed();
		if (won == true)
		{
			if (i == winner)
				temp.upWins();
			else
				temp.upLosses();
		}
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
    for (int i = 1; i < word.length(); i++)
	{
		_found += "_";
	}
}
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
player game::getPlayer(int pos)
{
	return players[pos];
}
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
		getline(fin, random);//this is the intro line(we could move that line to the end so that it doesn't butt in here)
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
		//if file exists with this player, read it and make player//done? does this work?
	}
	return nextPlayer;
}