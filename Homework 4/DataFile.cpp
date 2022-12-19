#include "DataFile.h"
#include <iostream>
using namespace std;

DataFile::DataFile(string filename, string data)//:AD_File(filename)
{
	try {
		this->setFilename(filename);
	}
	catch (string eror) {
		cout << eror << endl;
	}
	this->Data = data;
}

DataFile::DataFile()
{
	this->Filename = ""; this->Data = "";
}

void DataFile::setData(string newdata)
{
	this->Data = newdata;
}

bool DataFile::operator==(DataFile& const other)
{
	// Need to check if Parent operator can work here
	bool a = this->Filename == other.Filename;
	bool b = this->Data == other.Data;
	//bool c = this->getTime() == other.getTime();
	
	return a && b;
}
