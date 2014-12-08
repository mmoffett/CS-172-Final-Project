#include "player.h"

/*
* A default constructor for the player class.
*/
player::player()
{
	wins = 0;
	losses = 0;
	timesPlayed = 0;
}
/*
* A constructor for the player class.
*
* @param  _name		the player's name
*/
player::player(string _name)
{
	name = _name;
	wins = 0;
	losses = 0;
	timesPlayed = 0;
}

/*
* A constructor for the player class.
*
* @param  _name			the player's name
* @param  _wins			the number of wins player has
* @param _losses		the number of losses the player has
* @param _timesPlayed	the number of timesPlayed
*/
player::player(string _name, int _wins, int _losses, int _timesPlayed)
{
	name = _name;
	wins = _wins;
	losses = _losses;
	timesPlayed = _timesPlayed;
}

/*
* Returns the player's name.
*
* @return     the name
*/
string player::getName()
{
	return name;
}

/*
* Returns how many wins the player has.
*
* @return     the number of wins
*/
int player::getWins()
{
	return wins;
}

/*
* Returns how many losses the player has.
*
* @return     the number of losses
*/
int player::getLosses()
{
	return losses;
}

/*
* Returns the player's average.
*
* @return     the average
*/
double player::getAverage()
{
	double gamesWon = wins + losses;
	if ((gamesWon) > 0)
		return wins / gamesWon;
	else
		return 0;
}

/*
* Returns how many times the player has played.
*
* @return     the number of games played
*/
int player::getTimesPlayed()
{
	return timesPlayed;
}

/*
* Set's the players name.
*
* @param	_name     the player's name
*/
void player::setName(string _name)
{
	name = _name;
}

/*
* Increases the player's number of wins.
*/
void player::upWins()
{
	wins++;
}

/*
* Increases the player's number of losses.
*/
void player::upLosses()
{
	losses++;
}

/*
* Increases the player's number of games played.
*/
void player::upTimesPlayed()
{
	timesPlayed++;
}

/*
* Sets the player's win count.
*
* @param  win	the number of wins
*/
void player::setWinCount(int win)
{
	wins = win;
}

/*
* Sets the player's loss count.
*
* @param  loss	the number of losses
*/
void player::setLoss(int loss)
{
	losses = loss;
}

/*
* Sets the player's games played.
*
* @param  played	the games played
*/
void player::setTimesPlayed(int played)
{
	timesPlayed = played;
}

/*
* Adds a player to the player vector after reading any existing file for the player's stats.
* @return     the player that was just made
*/
void player::createPlayer()
{
	ifstream fin;
	cout << "Enter player name" << endl;
	cin >> name;
	string filename = name;
	filename += ".txt";//make the filename
	fin.open(filename);
	if (fin.fail())
	{
		cout << "Welcome, new player, " << name << "! \nYou currently have 0 wins, 0 losses, and no games played" << endl;
		timesPlayed = 0;
		wins = 0;
		losses = 0;
		//if this is a new player, set defaults
	}
	else
	{
		string random;
		string num;
		getline(fin, num);
		wins = atoi(num.c_str());
		getline(fin, num);
		losses = atoi(num.c_str());
		getline(fin, num);
		timesPlayed = atoi(num.c_str());
		cout << "Welcome, player, " << name << "! \nYou currently have " << wins << " wins, " << losses << " losses, and " << timesPlayed << " games played" << endl;
		//if file exists with this player, read it and make player
	}
}

/*
* Saves the scores of the player into the player file
*/
void player::saveScore()
{
	ofstream fout;
	string filename = name;
	filename += ".txt";
	fout.open(filename);//make or open file
	if (fout.fail())
	{
		cout << "can't open file" << endl;
		return;
	}
	fout << wins << endl;
	fout << losses << endl;
	fout << timesPlayed << endl;
	fout << getAverage() << endl;
	fout << name << endl;//give the file all of the data
	fout << "Information for Newest Data: Wins, Losses, Times Played, Average, Player Name\n";
	fout.close();
}