#include <iostream>
#include "Folder.h"

using namespace std;

int main() {
	Folder test("\\desktop", "easa.txt");

	cout << test.getFullPath() << endl;
	DataFile newfile("shhhDAW", "akhfkaj");
	DataFile newfile2("kajdkja", "dsahdhsa");

	test += newfile;
	test += newfile2;

	test.debugFunc1();

	return 0;
}