#include <iostream>
#include "AD_File.h"

using namespace std;

int main() {

	

	try {
		AD_File newfile("Hello.txt");

		cout << newfile.getTime() << endl;
		cout << newfile.getTime() << endl;
	}
	catch (char* err) {
		cout << err;
	}
	return 0;
}