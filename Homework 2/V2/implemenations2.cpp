#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "DataFile2.h"
#define length1 10
using namespace std;

#define OPT2 test[files] = opt2(); files++;
			

void opt1(DataFile** file, int len) ;
DataFile* opt2();
void opt3(DataFile** fileAdd, int len);
int getChoiceFromUser();

int main() {
	DataFile** test = new DataFile*[length1];
	int files = 0;

	while (1) {
		int choice = getChoiceFromUser();

		if (choice == 1) opt1(test, files);
		if (choice == 2) { OPT2 };
		if (choice == 3) opt3(test, files);
		if (choice == 4) break;
	}

	for (int j = 0; j < files; j++) {
		delete test[j];
	}
	delete[] test;

	cout << "Thanks for using Guy's And Neev's file system!" << endl;
	return 0;
}

void opt1(DataFile** file, int len) {
	if (len == 0) {cout << "No files as of now, come back later: " << endl; return;}

	for (int i = 0; i < len; i++)
		file[i]->dir();
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

void opt3(DataFile** fileAdd, int len) {
	cout << "Pls enter the name of the file u want to edit: " << endl;
	CONSOLECLEAR
	
	char buffer[50];
	gets_s(buffer, 49);

	for (int i = 0; i < len; i++)
	{
		if (strcmp(fileAdd[i]->getFileName(), buffer) == 0) {
			cout << "Enter the new data to the file" << endl;
			CONSOLECLEAR
				
			char buffer2[150];
			gets_s(buffer2);
			fileAdd[i]->editData(buffer2);
			return;
		}
	}
	cout << "File not found" << endl;
	return;
}
int getChoiceFromUser() {
	// All variables related to UI
	int option = 0;
	char options[4][30] = { "Print files", "Add file", "Edit file", "Exit" };
	
	// Printing of options
	cout << "Choose from the options :" << endl;
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ": " << options[i] << endl;
	}
	
	// Receving data from user about his choice
	cin >> option;
	
	// Minimalistic data checks
	if ((option < 1) || (option > 4)) {
		cout << "wrong key selected" << endl;
		return -1;
	}
	
	// Return user's choice
	return option;
}