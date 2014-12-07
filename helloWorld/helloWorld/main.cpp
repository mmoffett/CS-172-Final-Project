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
		test->openFile();//word is decided here
		while (gamewon == false)
		{
			int tries==6;
			while (tries>0)
			{
				for (int i = 0; i < numPlayers; i++)
				{
					bool correctGuess;
					cout << test->getPlayer(i).getName() << ", it is your turn";
					correctGuess = test->makeTurn();
					gamewon = test->winGame();
					if (gamewon == true)
					{
						cout << "Congratulations " << test->getPlayer(i).getName() << ", You Won\n" << endl;
						test->updatePlayers(true, i);
						tries = 0;
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


