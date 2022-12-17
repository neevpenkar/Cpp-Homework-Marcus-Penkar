#include "Folder.h"
#include <iostream>
#include <string>

using namespace std;
Folder::Folder(string path, string folderName)
{
	this->Path = path;
	this->FolderName = folderName;

	this->fileArray = NULL;
	this->folderArray = NULL;

	this->fileArrSize = 0;
	this->folderArrSize = 0;
}

Folder::Folder()
{
	Folder("", "");
}

Folder::Folder(const Folder& folder2) throw(string)
{
	throw("No Copy Constructor");
}

Folder::Folder(const Folder& folder2, string path)
{
	this->Path = path;
	*this = folder2;

	//for (int i = 0; i < this->fileArrSize; i++) {
	//	delete this->fileArray[i];
	//}
	//delete[] fileArray;

	//this->fileArray = new DataFile * [folder2.fileArrSize];
	//for (int i = 0; i < folder2.fileArrSize; i++) {
	//	this->fileArray[i] = new DataFile();
	//	*(this->fileArray[i]) = *(folder2.fileArray[i]);
	//}

}

void Folder::mkfile(string filename, string data) throw(string)
{
	try {
		DataFile temp(filename, data);
		*this += temp;
	}
	catch (string errorMsg) {
		throw(errorMsg);
	}
}

string Folder::getFullPath() const
{
	string temp;
	temp += this->Path + "\\" + this->Filename;
	return temp;
}

void Folder::operator+=(DataFile& const newfile) throw(string)
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
	// Check if file exists
	else {
		for (int n = 0; n < this->fileArrSize; n++)
			if (*(this->fileArray[n]) == newfile) {
				// cout << "File Exits" << endl;
				throw("File Exists");
				return;
			}

		// If file Does not exist
		// Make a temporary container
		DataFile* temp;
		temp = new DataFile[this->fileArrSize];

		// Copy from this object to temp all the internal objects
		for (int i = 0; i < this->fileArrSize; i++) {
			temp[i] = *this->fileArray[i];
		}

		// Clear internal objects of this
		for (int i = 0; i < this->fileArrSize; i++)
			delete this->fileArray[i];

		// Clear this->fileArray for reallocation
		delete[] this->fileArray;

		// Reallocate this->fileArray with one more object (address) to hold the new object
		this->fileArray = new DataFile * [this->fileArrSize + 1];

		// Insert all the stored objects from temp back to this object, while also allocating mem
		for (int i = 0; i < this->fileArrSize; i++) {
			this->fileArray[i] = new DataFile();
			*this->fileArray[i] = temp[i];
		}

		// Allocating memory and inserting the new object
		this->fileArray[this->fileArrSize] = new DataFile;
		*this->fileArray[this->fileArrSize] = newfile;

		// Updating the length of the array after insertion
		this->fileArrSize += 1;

		// Deleting the temporarily used temp object
		delete[] temp;
	}

}
// Throw an expception when folder already exists
void Folder::operator+=(Folder& const newfolder)
{
	if(folderArrSize==0)
	{
		folderArray = new Folder*;
		folderArray[0] = new Folder();
		*folderArray[0] = newfolder;
		this->folderArrSize += 1;
		return;
	}
	else {
		// Check if folder exists
		for (int n = 0; n < this->folderArrSize; n++)
			if (this->FolderName == newfolder.FolderName) {
				cout << "folder already Exits" << endl;
				//throw("Folder Exists");
				return;
			}
		// If the object does not already exist
		// Create a new temp obj, allocate enough memory length of old obj
		Folder* temp;
		temp = new Folder[this->folderArrSize];
		
		// Copy every Folder* from this obj to temp obj
		for (int i = 0; i < this->folderArrSize; i++) {
			temp[i] = *this->folderArray[i];
		}

		// Delete internal pointers
		for (int i = 0; i < folderArrSize; i++)
			delete this->folderArray[i];
		// Delete external pointers
		delete[] this->folderArray;

		// Reallocate this->FolderArray with one more address
		this->folderArray = new Folder * [this->folderArrSize + 1];

		// Copy all existing objects from temp back to this object
		// Go over all the indexes: allocate memory (an object) for each address and
		// copy each object from temp - operator = is implemented
		for(int i = 0; i < folderArrSize; i++)
		{
			folderArray[i] = new Folder();
			*folderArray[i] = temp[i];
		}

		// Allocate memory for new object and insert it into the array (folderArray)
		*folderArray[folderArrSize] = newfolder;

		// Delete temp object properly
		delete[] temp;
	}
}

void Folder::debugFunc1()
{
	for (int i = 0; i < this->fileArrSize; i += 1) {
		cout << this->fileArray[i]->getData() << endl;
	}
}

const Folder& Folder::operator=(const Folder& newfolder)
{
	if (&newfolder == this) return;

	this->FolderName = newfolder.FolderName;
	this->Path = newfolder.Path;
	this->folderArrSize = newfolder.folderArrSize;
	this->fileArrSize = newfolder.fileArrSize;

	for (int i = 0; i < this->fileArrSize; i++)
		delete this->fileArray[i];
	delete[] this->fileArray;

	for (int i = 0; i < this->folderArrSize; i++)
		delete this->folderArray[i];
	delete[] this->folderArray;

	this->fileArray = new DataFile * [newfolder.fileArrSize];
	this->folderArray = new Folder * [newfolder.folderArrSize];

	for (int i = 0; i < newfolder.fileArrSize; i++) {
		this->fileArray[i] = new DataFile();
		*(this->fileArray[i]) = *(newfolder.fileArray[i]);
	}

	for (int i = 0; i < newfolder.folderArrSize; i++) {
		this->folderArray[i] = new Folder();
		*(this->folderArray[i]) = *(newfolder.folderArray[i]);
	}
}
