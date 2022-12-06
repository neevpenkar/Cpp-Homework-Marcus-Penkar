#include "Folder.h"
#define _CRT_SECURE_NO_WARNINGS


Folder::Folder(const char* name, const char* path)
{
	this->folderName = new char[strlen(name) + 1];
	this->path = new char[strlen(path) + 1];

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

void Folder::classEditHelper()
{
	delete[] this->folderName;
	delete[] this->path;
}

void Folder::debugFunc1()
{
	cout << this->folderName << endl;
	cout << this->path << endl;
}

Folder::~Folder()
{
	delete[] this->folderName;
	delete[] this->path;
}
