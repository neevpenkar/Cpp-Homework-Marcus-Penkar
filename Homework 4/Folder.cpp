#include "Folder.h"

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
