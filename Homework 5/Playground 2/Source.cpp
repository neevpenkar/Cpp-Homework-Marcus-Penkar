#include <iostream>
#include "AD_File.h"
#include "DataFile.h"
#include "Folder.h"

using namespace std;

int main() {

    Folder t1("TestR", "pathtest");
    t1.Root += &t1;

    AD_File* temp = t1.cd("TestR");

    cout << temp->getName() << endl;

	return 0;
}


/*
* // [3/4]: SearchFunction
Folder* Folder::SearchFunction(Folder* root, const string path) throw(string)
{
    // Case (1/3): single element path - returns the root
    if (getCurrentDir(path) == "<END>")
    {
        return root;
    }

    // Case (2/3): multi element path - searches for the folder name
    string curr = getCurrentDir(path);
            // Example path:    C:\Myfiles\Folder2
    int temp = root->localFind(curr);
    if (temp == -1)
    {
        // Case (3/3): Folder not found
        throw(string("folder not found"));
    }
    else
    {
        Folder* TMP = dynamic_cast<Folder>((root)[temp]);
        if (TMP)
        {
            try
            {
                return SearchFunction(TMP, getNextDirs(path));
            }
            catch (string error)
            {
                throw (error);
            }
        }
        else
        {
            throw(string("Path contains a file and not a folder.\n"));
        }
    }
}
*/