#include "Folder.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

Folder::Folder(const char* name, const char* path)
{
	// Allocation
	this->folderName = new char[strlen(name) + 1];
	this->path = new char[strlen(path) + 1];

	// Init
	strcpy(this->folderName, name);
	strcpy(this->path, path);
}

Folder::Folder(const Folder& newitem)
{
	delete[] this->folderName;
	delete[] this->path;

	this->folderName = new char[strlen(newitem.folderName) + 1];
	this->path = new char[strlen(newitem.path) + 1];

	strcpy(this->folderName, newitem.folderName);
	strcpy(this->path, newitem.path);

	this->fileArray = newitem.fileArray;
}

void Folder::readAllFiles()
{
	char buffer[200];

	strcpy(buffer, this->path);
	//strcat(buffer, "\\");
	strcat(buffer, this->folderName);

	try {
		this->fileArray.ArrayDataFiles::readAllFiles(buffer);
	}
	catch (int errorCode) {
		if (errorCode == -1) {
			cout << "Error Opening File!" << endl;
			cout << "# Make sure the file exists and is name has been entered correctly" << endl;
			return;
		}
	}
}

const Folder& Folder::operator=(const Folder& fol)
{
	// Delete Existing memory - make room for new
	delete [] this->folderName;
	delete [] this->path;

	// Allocate memory which is newly freed
	this->folderName = new char[strlen(fol.folderName) + 1];
	this->path = new char[strlen(fol.path) + 1];

	// Insert data from fol into this
	strcpy(this->folderName, fol.folderName);
	strcpy(this->path, fol.path);

	// Take care of Array Data File
	this->fileArray = fol.fileArray;

	// insert return statement here
	return *this;
}

bool Folder::operator==(const Folder& fol)
{
	if (this->fileArray.len != fol.fileArray.len)
		return false;
	
	// Go over all items in ArrayDataFile object and check if they are the same

	// We will 
	for (int i=0;i<fileArray.len;i++)
	{
		bool temp = *(this->fileArray.filePointArr[i]) == *(fol.fileArray.filePointArr[i]);
		if (temp == 0) return 0;
	}
	return 1;
}

void Folder::operator+=(const DataFile newfile)
{
	this->fileArray += newfile;
}

void Folder::classEditHelper()
{
	delete[] this->folderName;
	delete[] this->path;
}

void Folder::debugFunc1()
{
	for (int y = 0; y < fileArray.len; y++) {
		this->fileArray.filePointArr[y]->dir();
	}
}

Folder::~Folder()
{
	delete[] this->folderName;
	delete[] this->path;
}

ostream& operator<<(ostream& out, Folder const& folder)
{
	out << folder.path << "\\" << folder.folderName << endl;

	for (int i = 0; i < folder.fileArray.len; i++)
	{
		out << *(folder.fileArray.filePointArr[i]);
	}
	
	return out;
}
