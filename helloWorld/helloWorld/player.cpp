
#include "player.h"

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