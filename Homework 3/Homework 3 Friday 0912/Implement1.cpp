#include <iostream>
#include "ArrayDataFiles.h"
#include "DataFile.h"
#include "Folder.h"

using namespace std;

int main() {
	// Question 1
	Folder testF("ListDataFiles.txt", "");

	// Question 2
	testF.Folder::readAllFiles();

	// Question 3
	cout << testF << endl;

	// Question 4 -> As if the user had inputed arguments:
	DataFile file1("firstfile.txt", "is it working? BIIIIIIIIIIIIIIIIIIIIIIG");
	DataFile file2("seondfile.txt", "is it working?");

	try {
		testF.getDataFiles() += file1;
		testF.getDataFiles() += file2;
	}
	catch (const char* Emsg) {
		cout << Emsg << endl;
	}
	testF.debugFunc1();
	cout << endl << endl;

	// Question 6
	testF.getDataFiles().bigFile_2()->dir();

	// Question 7 -> Assume arguments were inputed by user:
	Folder folder2("StamFile.txt", "");

	DataFile exe1 ("MahKoreh.txt", "Guy");
	DataFile exe2 ("MaKoreh.txt", "Neev");

	// Question 8
	folder2 += exe1; folder2 += exe2;
	cout << (testF == folder2) << endl;
	//folder2 = testF;
	//cout << (testF == folder2) << endl;

	return 0;
}