#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "DataFile.h"
using namespace std;

bool isEmpty(int length) { return length > 0; }
//bool isEmpty(int length) { DataFile }
int getChoiceFromUser();

#define DATABUFFER 1000

int main() {
	// All variables related to File Interface
	long length = 0;
	DataFile* fileArr = new DataFile[length];

	while (1) {
		int localOpt = getChoiceFromUser();
		while (localOpt == -1) localOpt = getChoiceFromUser();

		if (localOpt == 1) {
			if (length == 0) {
				cout << "No Files yet, pls try again later: " << endl;
				continue;
			}
			
			for (int i = 0; i < length; i++) {
				fileArr[i].dir();
			}
		}

		if (localOpt == 2) {
			// User wants to add a new file
			// Taking info about new file from user
			char newname[40];
			cout << "Please enter the name of the new file (max 40 chars): " << endl;
			gets_s(newname, 40);

			cin.clear();
			cin.ignore(INT_MAX, '\n');

			char newdata[DATABUFFER];
			cout << "Please enter data:  " << endl;
			gets_s(newdata, DATABUFFER);

			DataFile* newArr = new DataFile[length + 1];
			for (int i = 0; i < length; i++) {
				newArr[i] = fileArr[i];
			}

			// Debug
			DataFile(newname, newdata).dir();

			newArr[length] = DataFile(newname, newdata);
			length++;

			DataFile* temp = fileArr;
			fileArr = newArr;
			delete[] temp;
			
		}
		else if (localOpt == 3) {
			// Editing file

			// Check if files exist
			if (length == 0) {
				cout << "No files exist yet" << endl;
				continue;
			}

			// Edit file
			// For that, for comfort reasons, I will print all files first
			cout << "Choose from the files below :" << endl;
			for (int i = 0; i < length; i++) cout << i + 1 << ": " << fileArr[i].getFileName() << endl;

			char namebuf[40];
			gets_s(namebuf, 40);
			DataFile* wanted = NULL;

			for (int u = 0; u < length; u++)
				if (fileArr[u].getFileName() == namebuf) wanted = fileArr + u;

			while (wanted == NULL) {
				cout << "No such file! Try again " << endl;
				gets_s(namebuf, 40);
				for (int u = 0; u < length; u++)
					if (fileArr[u].getFileName() == namebuf) wanted = fileArr + u;
			}
			
			cout << "Okay, enter new data: " << endl;
			char databuf[DATABUFFER];
			gets_s(databuf, DATABUFFER);

			wanted->setData(databuf);
			cout << "Done Editing" << endl;
		}

		else if (localOpt == 4) break;
	
	}
	
	cout << "Thanks for using Guy's And Neev's file system!" << endl;
	return 0;
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

