#include <iostream>
#include <string>
#include "game.h"
#include "player.h"

using namespace std;

int main()
{

	game *test = new game();

	int numPlayers = 0;
	while (numPlayers <= 0 || numPlayers > 6)
	{
		cout << "How many players are there? " << endl;
		cin >> numPlayers;
	}//finds number of players between 1 and 6
	bool gamewon = false;

	for (int i = 0; i < numPlayers; i++)
	{
		player temp = *new player();
		temp.createPlayer();
		test->addPlayer(temp);
	}//fills the game's vector of players
	bool gameDone = false;
	while (gameDone == false)//while people still want to play
	{
		test->play();//runs a round of the game

		cout << "GAME OVER \nWould you like to play again? (y/n) \n";
		char replay;
		cin >> replay;
		if (replay != 'y' && replay != 'Y')//if do not answer yes to play again
		{
			test->saveScores();//update all of the players files
			cout << "Goodbye!";
			for (int i = 0; i < numPlayers; i++)//return each player's average score
			{
				cout << test->getPlayer(i).getName() << " has an average score of " << test->getPlayer(i).getAverage() << endl;
			}
			gameDone = true;
		}
	}

	cout << "Press any key to continue: ";
	char end;
	cin >> end;
}