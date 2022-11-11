#define _crt_secure_no_warnings
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


unsigned int num_of_spaces(char* str) {
	 // make a (local) copy of (string) so that it can be manipulated locally
	char* sentence = new char[strlen(str) + 1];
	strcpy(sentence, str);

	 // init temp (loop variable) and counter
	char* temp = strtok(sentence, " ");
	unsigned int counter = 0;

	 // strtok will return after no spaces are left, catch that! 
	while (temp != NULL) {
		counter++;
		temp = strtok(NULL, " ");
	}

	 // free sentence as it is auxilary memory
	delete[] sentence;
	return counter - 1;
}

char*** dividestring(char* sentence, int& length) {
	 // get the number of spaces, which also is the number of times i will aplly strtok
	int spaces = num_of_spaces(sentence);
	length = num_of_spaces(sentence);

	 // make an array of strings, the length of which is the number of spaces
	 // + 1 is for margin
	char** arr = new char* [spaces + 1];

	 // init strtok (loop variable)
	char* temp = strtok(sentence, " ");

	 /*for every turn in the loop, i will always have a new word in temp, a string with 
	 custom length needs to be created to store each word seperately. each string is stored
	 in arr, the array of strings i created above. each string is allocated customly, and after 
	 allocation, temp which stores current word is copied into the array. 
	 after that, new word is introduced in temp.*/

	for (int i = 0; i < spaces + 1; i++) {
		int length = strlen(temp);
		arr[i] = new char[length + 1];
		strcpy(arr[i], temp);
		temp = strtok(NULL, " ");
	}
	 //return the address of arr so it can be used in main 
	return &arr;
}

int main() {
	char str[] = "hello world what is this?";
	int length;
	char*** temp = dividestring(str, length);
	char** container = *temp;

	for (int i = 0; i < length + 1; i++) {
		cout << container[i] << endl;
		delete[] container[i];
	}
	delete[] *temp;
	
	return 0;
}



void change_string(char** add) {
		int length = strlen(*add);
	
		// allocate a temporary string which will be copy of orginal string
		char* temp = new char[length + 1];
		strcpy(temp, *add);
	
		// free add, basically reassign it
		// on second thoughts, i'll realloc it, i have no koach
		char** t = add;
		*add = (char*)realloc(*add, 2 * length + 1);
		if (*add == NULL) exit(-5);
	
		// copy the temp string into the original string
		// then concatenate the same temp string onto the orig string to get 2 copies

		strcpy(*add, temp);
		strcat(*add, temp);
		return;
	}
	
int main() {
	char sentence[] = "love";
	
	char* testbench = new char[strlen(sentence) + 1];
	strcpy(testbench, sentence);
	
	change_string(&testbench);
	cout << testbench << " size: " << strlen(testbench) + 1<< endl;
	
	return 0;
}