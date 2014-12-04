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

		cout << "How many players are there? " << endl;
		int numPlayers;
		cin >> numPlayers;
	    bool gamewon = false;
		player *winner;

		for (int i = 0; i < numPlayers; i++)
		{

			test->addPlayer(test->createPlayer());//newP will be filled with diff contents
		}
		test->openFile();//word is decided here
		while (gamewon == false)
		{
			//int tries;
			for (int tries = 0; tries < 6; tries++)
			{
				for (int i = 0; i < numPlayers-1; i++)
				{
					cout << test->getPlayer(i).getName() << ", it is your turn";
					gamewon = test->makeTurn(test->getPlayer(i), winner);
					if (gamewon == true)
					{
						cout << "Congratulations " << test->getPlayer(i).getName() << ", You Won\n" << endl;
						test->updatePlayers(true, i);
					}

				}
			}

				cout << "GAME OVER \n Would you like to play again? (y/n) \n";
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


