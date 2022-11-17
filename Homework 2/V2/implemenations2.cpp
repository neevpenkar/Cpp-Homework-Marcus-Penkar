#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "DataFile2.h"
#define length1 10
using namespace std;

void opt1(DataFile* file, int len) ;
//void opt2(DataFile* file, int & len);
DataFile* opt2();

int main() {
	DataFile** test = new DataFile*[length1];
	int files = 0;

	test[files] = opt2();
	files++;

	opt1(*test, files);
	
	for (int j = 0; j < files; j++) {
		delete test[j];
	}
	delete[] test;
	return 0;
}

void opt1(DataFile* file, int len) {
	if (len == 0) {cout << "No files as of now, come back later: " << endl; return;}

	for (int i = 0; i < len; i++)
		file[i].dir();
}

DataFile* opt2() {
	char buff1[50], buff2[200];
	cout << "Please enter the name of the file you want to add: " << endl;
	CONSOLECLEAR
	gets_s(buff1, 49);
		
	cout << "Please enter the data you want to add: " << endl;
	CONSOLECLEAR
	gets_s(buff2, 199);

	DataFile* file = new DataFile;
	
	// Should be done in constructor but that drat thing is not working
	file->setFileName(buff1);
	file->setData(buff2);
	file->setTime();

	// DataFile(buff1, buff2);

	return file;
}
//void opt2(DataFile* file, int & cursor) {
//	char buff1[50], buff2[200];
//	cout << "Please enter the name of the file you want to add: " << endl;
//	CONSOLECLEAR
//	gets_s(buff1, 49);
//	
//	cout << "Please enter the data you want to add: " << endl;
//	CONSOLECLEAR
//	gets_s(buff2, 199);
//
//	DataFile(buff1, buff2).dir();
//	file[cursor] = ;
//	cursor++;
//	return;
//}