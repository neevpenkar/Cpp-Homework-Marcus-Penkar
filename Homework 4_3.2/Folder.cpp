#include "Folder.h"
#include <iostream>

using namespace std;

Folder Folder::Root("root", "");

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

Folder::Folder(const Folder& fol, string path):AD_File(fol.Name)
{
	for (int i = 0; i < this->kvazim.length; i++)
		delete (this->kvazim.arr)[i];
	delete[](this->kvazim.arr);

	this->kvazim.arr = new DataFile * [fol.kvazim.length];

	for (int i = 0; i < fol.kvazim.length; i++) {
		*this += *fol.kvazim.arr[i];
	}

	this->Path = path;
}

string Folder::getFullPath() const
{
	string temp = "";
	temp += this->Path;
	temp += "\\";
	temp += this->Name;
	return temp;
}

void Folder::mkfile(string name, string data) throw(string)
{
	try {
		*this += DataFile(name, data);
	}
	catch (string err)
	{
		throw err;
	}
}

void Folder::mkdir(string name) throw(string)
{
	try{
	*this += Folder(name,this->getFullPath());
	}
	catch (string err)
	{
		throw err;
	}
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

void Folder::cd(string path) throw(string)
{
	const static char token = '\\';

	if (path.find(token) == -1) {
		cout << path << endl;
		return;
	}

	int slashIndex = path.find(token);
	string currentPane = path.substr(0, slashIndex);

	// Check if currentPane exists in this object
	bool exists = false;
	for (int i = 0; i < this->tikiot.length; i++) {
		if (this->tikiot.arr[i]->Name == currentPane) exists = true;
	}
	if (!exists) {
		throw(string("Folder Not found!"));
		return;
	}

	this->cd(path.substr(slashIndex + 1, path.length()));
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

const Folder& Folder::operator=(const Folder& fold)
{
	// Init temp object
	Folder** temp = new Folder * [fold.tikiot.length];
	DataFile** temp2 = new DataFile * [fold.kvazim.length];

	// Copy all folder objects into temp from argument folder
	for (int i = 0; i < fold.tikiot.length; i++)
		temp[i] = new Folder(fold.tikiot.arr[i]->Name, fold.tikiot.arr[i]->Path);
	
	// Copy all file objects into temp2 from argument file
	for (int i = 0; i < fold.kvazim.length; i++)
		temp2[i] = new DataFile(fold.kvazim.arr[i]->Name, fold.kvazim.arr[i]->Data);

	// Delete existing file and folder containers
	for (int i = 0; i < this->kvazim.length; i++)
		delete (this->kvazim.arr)[i];
	delete[](this->kvazim.arr);

	for (int i = 0; i < this->tikiot.length; i++)
		delete (this->tikiot.arr)[i];
	delete[](this->tikiot.arr);

	// Reassigment of arrays
	this->tikiot.arr = temp;
	this->kvazim.arr = temp2;

	this->tikiot.length = fold.tikiot.length;
	this->kvazim.length = fold.kvazim.length;

	AD_File::operator=(fold);

	// // O: insert return statement here
	return *this;
}



