#include <iostream>
#include <string>
#include "game.h"
#include "player.h"

using namespace std;

int main()
{
    
    char replay = 'y';
    while (replay == 'y' || replay == 'Y')
    {
		game *test = new game();

		int numPlayers = 0;
		while (numPlayers <= 0 || numPlayers < 6)
		{
			cout << "How many players are there? " << endl;
			cin >> numPlayers;
		}
	    bool gamewon = false;
		
		for (int i = 0; i < numPlayers; i++)
		{

			test->addPlayer(test->createPlayer());//newP will be filled with diff contents
		}
		bool gamewon = false;
		while (gamewon == false)
		{
			test->play();

			cout << "GAME OVER \nWould you like to play again? (y/n) \n";
			test->updatePlayers(false, 100);
			cin >> replay;
			if (replay != 'y' && replay != 'Y')
			{
				test->saveScores();
				cout << "Goodbye!";
				for (int i = 0; i < numPlayers; i++)
				{
					cout << test->getPlayer(i).getName() << " has an average score of " << test->getPlayer(i).getAverage();
				}
			}
			else
				gamewon = false;
		}

		}
	}


}


