#include <iostream>
#include "DataFile.h"


using namespace std;

int main() {
	DataFile file, file2;
	cout << file.getFileName() << endl;
	cout << file2.getFileName() << endl;

	//cout << (file == file) << endl; // Works!


	return 0;
}