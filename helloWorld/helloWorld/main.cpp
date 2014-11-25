#define __APPLE__ // Comment this line out when compiling on a Windows platform

#ifdef __APPLE__
#include "CoreFoundation/CoreFoundation.h"
#endif


#include <iostream>
#include <string>
#include "game.h"
#include "player.h"

using namespace std;

int main(){
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
    
    // TO DO LIST:
    
    
    // Ask how many players
    // Create or access that many players
        // Create vector; access or create each player file
    
    // Create game
    // Run game
        // How are we going to rotate turns?
        // Track how many tries are left
        // Update the "ASCII" function
        //In a for loop -> "Do you want to play again?"
    // These are both in the game class!
    
    // Output who won each game
    // Output player averages
    // Update scores when program closes

}




#endif
