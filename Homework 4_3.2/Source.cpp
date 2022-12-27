#include <iostream>
#include "AD_File.h"
#include "DataFile.h"
#include "Folder.h"

using namespace std;
int main() {
	Folder temp("", "");
	Folder test1("Guy", "dfhkdui");
	Folder test2("Neev", "fdaf");
	
	temp.Root += test1;
	temp.Root += test2;

	try {
		Folder* changed = temp.cdTest(&(temp.Root), "Guy\\");
		//cout << changed->getName() << endl;
		*changed += Folder("test1", "Dasdas");
		*changed += Folder("Bibi", "Dasdas");

		//changed->dir();
		//cout << changed->getName() << endl;
		
		// Check
		Folder* changed2 = temp.Root.cdTest(&(temp.Root), "Guy\\Bibi\\");
		cout << changed2->getName() << endl;
		cout << changed2->getFullPath() << endl;
	}
	catch (string error) {
		cout << error << endl;
	}
	catch (...) {
		cout << "Errror" << endl;
	}
	return 0;
}