#include "Folder.h"

// ASK Maayan about throw catch in פקודת איתחול
// Init line catching exceptions

Folder::Folder(string foldername, string path):AD_File(foldername)
{
	this->Path = path;

	this->kvazim.arr = NULL;
	this->tikiot.arr = NULL;

	this->kvazim.length = 0;
	this->tikiot.length = 0;
}
// AD_file no empty constructor exists
Folder::Folder(const Folder& fol) throw(string) :AD_File("")
{
	throw("No Copy Constructor!");
}

string Folder::getFullPath() const
{
	string temp = "";
	temp += this->Path;
	temp += "\\";
	temp += this->Name;
	return temp;
}

void Folder::operator+=(const DataFile& file) throw(string)
{
	if (this->kvazim.length = 0) {
		this->kvazim.arr = new DataFile*;
		*(this->kvazim.arr) = new DataFile(file.Name, file.Data);
		this->kvazim.length ++;
	}
	else {
		for (int i = 0; i < this->kvazim.length; i++)
			if (*(this->kvazim.arr[i]) == file) throw("File Exists!");

		DataFile** temp = new DataFile * [this->kvazim.length + 1];

		for (int i = 0; i < this->kvazim.length; i++) {
			temp[i] = new DataFile(this->kvazim.arr[i]->Name, this->kvazim.arr[i]->Data);
		}

		temp[this->kvazim.length] = new DataFile(file.Name, file.Data);
		this->kvazim.length++;
	}
}
