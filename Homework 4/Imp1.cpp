#include <iostream>
#include "Folder.h"

using namespace std;

int main() {
	Folder test("\\desktop", "easad");
	Folder test2("ahsoah", "dgdisgdiwgdiwuq");

	//cout << test.getFullPath() << endl;
	DataFile newfile("shhhDAW", "akhfkaj");
	DataFile newfile2("kajdkja", "dsahdhsa");

	test += newfile;
	test += newfile2;
	test += test2;

	test.dir();

	return 0;
}