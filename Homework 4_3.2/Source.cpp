#include <iostream>
#include "AD_File.h"
#include "DataFile.h"
#include "Folder.h"

using namespace std;
int main() {
	Folder test("Av", "\\root");
	Folder test23("asdsa", "dsadsd");

	DataFile file("Ben File", "testDaata");
	DataFile file2("Ben file2", "rsakajc");

	test += file;
	test += file2;

	test += test23;

	test.dir();
	//cout << test.;

	return 0;
}