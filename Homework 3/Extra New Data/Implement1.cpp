#include <iostream>
#include "ArrayDataFiles.h"
#include "DataFile.h"
#include "Folder.h"

using namespace std;


int main() {
	ArrayDataFiles testArr;
	testArr.readAllFiles("ListDataFiles.txt");
	testArr.debugFunc();

	return 0;
}





//
//int main() {
//	Folder f1("dsd", "qee");
//	Folder f2("", "");
//
//	f2.debugFunc1();
//	return 0;
//}
//
//
//
//
//
//
////int main() {
////	ArrayDataFiles arr1;
////
////	DataFile test1("Hello", "Hello World");
////	DataFile test2("C", "C++ is sooo hard!");
////	DataFile test3("C++", "C is sooo hard!fddewdeewwe");
////	DataFile test4("Meh", "woeyqwouyeuqwwwwwwwwwwwwwafqeqewqqe");
////	
////	
////	arr1 += test1;
////	arr1 += test2;
////	arr1 += test4;
////	arr1 += test3;
////
////	cout << arr1.bigFile() << endl;
////
////	return 0;
////}
////int main() {
////	DataFile file1("Hasddqdqqdq", "djkwchjddddddddddddddddd");
////	DataFile file2;
////	DataFile file3;
////
////	file2 = file1;
////	file3 = file2;
////
////	file1.dir();
////	file2.dir();
////	file3.dir();
////
////	return 0;
////}