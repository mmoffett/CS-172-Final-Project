#define __APPLE__ // Comment this line out when compiling on a Windows platform

#ifdef __APPLE__
#include "CoreFoundation/CoreFoundation.h"
#endif


#include <iostream>
#include <string>
#include "game.h"
#include "player.h"
#include "game.cpp"
#include "player.h"

using namespace std;

int main()
{
    // ----------------------------------------------------------------------------
    // This makes relative paths work in C++ in Xcode by changing directory to the Resources folder inside the .app bundle
	#ifdef __APPLE__
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
    {
        // error!
    }
    CFRelease(resourcesURL);
    
    chdir(path);
    std::cout << "Current Path: " << path << std::endl;
    // ----------------------------------------------------------------------------
    
    char replay;
    while (replay == 'y' || replay == 'Y')
    {
		game test = (*new game());

		cout << "How many players are there? " << endl;
		int numPlayers;
		cin >> numPlayers;
		//vector <player> players;
	    bool gamewon = false;
		player *winner;

		for (int i = 0; i < numPlayers; i++)
		{
			cout << "Enter player name" << endl;
			string name;
			cin >> name;
			//if file exists with this player, read it and make player
			//else make new file and make player
			player newP = (*new player(name));
			//players.push_back(newP);--> don't need to store this within main because we just access the one game has
			test.addPlayer(newP);//newP will be filled with diff contents
		}
		test.openFile();
		while (gamewon == false)
		{
			int tries;
			for (tries = 0; tries < 6; tries++)
			{
				for (int i = 0; i < numPlayers-1; i++)
				{
					cout << test.getPlayer(i).getName() << ", it is your turn";
					gamewon = test.makeTurn(test.getPlayer(i), winner);
					 // Since we don't have file i/o working very well right now, I'm using syzygy as a stand-in word.
				}
			}
			if (tries == 0)
			{
				cout << "GAME OVER \n Would you like to play again? (y/n) \n";
				cin >> replay;
				if (replay != 'y' && replay != 'Y')
					//This is where we should put the code to commit scores
					cout << "Goodbye!";
            
			}
		}
	}


    // TO DO LIST:
    
    
    // Ask how many players//done
    // Create or access that many players
        // Create vector;//done
		//access or create each player file
    
    // Create game//done
    // Run game
        // How are we going to rotate turns? // mostly done, needs some fixes
        // Track how many tries are left // Done!
        // Update the "ASCII" function
        //In a for loop -> "Do you want to play again?" // Done!
    // These are both in the game class!
    
    // Output who won each game
    // Output player averages
    // Update scores when program closes

}




#endif
