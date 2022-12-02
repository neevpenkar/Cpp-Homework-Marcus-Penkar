#include <iostream>
#include "ArrayDataFiles.h"
#include "DataFile.h"

using namespace std;

int main() {
	ArrayDataFiles arr1;
	ArrayDataFiles arr2;

	DataFile test1("Hello", "Hello World");
	DataFile test2("C", "C++ is sooo hard!");
	
	arr1 += test1;
	arr1 += test2;

	return 0;
}