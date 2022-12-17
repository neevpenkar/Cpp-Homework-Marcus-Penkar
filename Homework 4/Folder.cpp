#include "Folder.h"
#include <iostream>
#include <string>

using namespace std;
Folder::Folder(string path, string filename):DataFile(filename, "")
{
	this->Path = path;
}

string Folder::getFullPath() const
{
	string temp;
	temp += this->Path + "\\" + this->Filename;
	return temp;
}

void Folder::operator+=(DataFile& const newfile)//:throw(string)
{
	// Length = 0, needs allocation
	if (this->fileArrSize == 0) {
		fileArray = new DataFile*;
		fileArray[0] = new DataFile();
		*fileArray[0] = newfile;
		this->fileArrSize += 1;
		return;
	}
	// Length != 0
	else {
		// Check if file exists
		for (int n = 0; n < this->fileArrSize; n++)
			if (*(this->fileArray[n]) == newfile) {
				cout << "File Exits" << endl;
				//throw("File Exists");
				return;
			}

		// If file Does not exist
		DataFile* temp;
		temp = new DataFile[this->fileArrSize];

		for (int i = 0; i < this->fileArrSize; i++) {
			temp[i] = *this->fileArray[i];
		}

		for (int i = 0; i < this->fileArrSize; i++)
			delete this->fileArray[i];
		delete[] this->fileArray;

		this->fileArray = new DataFile * [this->fileArrSize + 1];

		for (int i = 0; i < this->fileArrSize; i++) {
			this->fileArray[i] = new DataFile();
			*this->fileArray[i] = temp[i];
		}

		this->fileArray[this->fileArrSize] = new DataFile;
		*this->fileArray[this->fileArrSize] = newfile;
		this->fileArrSize += 1;

		delete[] temp;
	}

}

void Folder::debugFunc1()
{
	for (int i = 0; i < this->fileArrSize; i += 1) {
		cout << this->fileArray[i]->getData() << endl;
	}
}
