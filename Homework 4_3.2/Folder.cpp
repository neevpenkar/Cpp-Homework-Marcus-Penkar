#include "Folder.h"
#include <iostream>

using namespace std;
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

void Folder::dir() const
{
	for (int i = 0; i < this->kvazim.length; i++)
		(this->kvazim.arr)[i]->cat();

	for (int i = 0; i < this->tikiot.length; i++)
		(this->tikiot.arr)[i]->cat();
}

void Folder::cat() const
{
	AD_File::cat2();
	cout << endl;
}

Folder::~Folder()
{
	for (int i = 0; i < this->kvazim.length; i++)
		delete (this->kvazim.arr)[i];
	delete[](this->kvazim.arr);

	for (int i = 0; i < this->tikiot.length; i++)
		delete (this->tikiot.arr)[i];
	delete[](this->tikiot.arr);
}

void Folder::debugFunc1() const
{
	for (int i = 0; i < this->kvazim.length; i++) {
		this->kvazim.arr[i]->cat();
	}
}

Folder& Folder::operator+=(const DataFile& file) throw(string)
{
	if (this->kvazim.length == 0) {
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

		for (int i = 0; i < this->kvazim.length; i++)
			delete (this->kvazim.arr)[i];
		delete[](this->kvazim.arr);

		this->kvazim.arr = temp;
		temp = NULL;
		this->kvazim.length++;
	}
	return *this;
}

Folder& Folder::operator+=(const Folder& fold) throw(string)
{
	if (this->tikiot.length == 0) {
		this->tikiot.arr = new Folder*;
		*(this->tikiot.arr) = new Folder(fold.Name, this->getFullPath());
		this->tikiot.length++;
	}
	else {
		for (int i = 0; i < this->tikiot.length; i++)
			if (*(this->tikiot.arr[i]) == fold) throw("fold Exists!");

		Folder** temp = new Folder * [this->tikiot.length + 1];

		for (int i = 0; i < this->tikiot.length; i++) {
			temp[i] = new Folder(this->tikiot.arr[i]->Name, this->getFullPath());
		}

		temp[this->tikiot.length] = new Folder(fold.Name, this->getFullPath());

		for (int i = 0; i < this->tikiot.length; i++)
			delete (this->tikiot.arr)[i];
		delete[](this->tikiot.arr);

		this->tikiot.arr = temp;
		temp = NULL;
		this->tikiot.length++;
	}
	return *this;
}



