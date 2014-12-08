
#include "player.h"

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
		return wins / (wins + losses);
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