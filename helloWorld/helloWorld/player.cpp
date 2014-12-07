
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
		if ((wins + losses) > 0)
			return wins / (wins + losses);
		else
			return 0;
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
    void player::setWinCount(int win)
    {
        wins = win;
    }
    void player::setLoss(int loss)
    {
        losses = loss;
    }
    void player::setTimesPlayed(int played)
    {
        timesPlayed = played;
    }