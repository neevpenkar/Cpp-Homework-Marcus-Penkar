#include "Folder.h"

/*Folder Folder::addFileToArray()
{
	this->folderArray;
	return Folder();
}

bool Folder::operator==(const Folder& fol)
{
	if (this->fileArray.len != fol.fileArray.len)
		return false;

	// Go over all items in ArrayDataFile object and check if they are the same
	// We will
	for (int i = 0; i < fileArray.len; i++)
	{
		bool temp = *(this->fileArray.filePointArr[i]) ==
			*(fol.fileArray.filePointArr[i]);
		if (temp == 0) return 0;
	}
	return 1;
}

void Folder::operator+=(const Folder newfolder)
{
	if (this->len == 0) {
		this->len++;
		this->folderArray = new Folder*;
	//	this->folderArray[0] = new Folder;
		*(this->folderArray[0]) = newfolder;
	}
	else {
		// Check if the file already exists
		for (int n = 0; n < this->len; n++)
			if (*(this->folderArray[n]) == newfolder) {
				throw("File Exists");
				return;
			}
}

void Folder::operator+=(const DataFile newfile)
{
	this->folderArray += newfile;
}

const Folder& Folder::operator=(const Folder& newfile)
{

	this->setFileName(newfile.getFileName());
	this->editData(newfile.getData());
	this->setTimeManually(newfile.getTimeObj());

	return *this;
}*/

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

