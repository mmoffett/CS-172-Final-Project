
#include "player.h"


player::player(string _name)
{
	name = _name;
	wins = 0;
	losses = 0;
	timesPlayed = 0;
}
player::player(string _name, int _wins, int _losses, int _timesPlayed)
{
	name = _name;
	wins = _wins;
	losses = _losses;
	timesPlayed = _timesPlayed;
}
    string player::getName()
    {
        return name;
    }
    int player::getWins()
    {
        return wins;
    }
    int player::getLosses()
    {
        return losses;
    }
    double player::getAverage()
    {
        return wins / (wins + losses);
    }
    int player::getTimesPlayed()
    {
        return timesPlayed;
    }
    void player::setName(string _name)
    {
        name = _name;
    }
	void player::upWins()
	{
		wins++;
	}
	void player::upLosses()
	{
		losses++;
	}
	void player::upTimesPlayed()
	{
		timesPlayed++;
	}