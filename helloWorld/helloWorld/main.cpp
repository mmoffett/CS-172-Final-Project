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
    
}




#endif
