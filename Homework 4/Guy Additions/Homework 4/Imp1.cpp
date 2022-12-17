#include <iostream>
#include "Folder.h"

using namespace std;

int main() {
	Folder test("\\desktop", "easa.txt");
	cout << test.getFullPath() << endl;
	cout << test.MainFolder.getFullPath() << endl;
	return 0;
}