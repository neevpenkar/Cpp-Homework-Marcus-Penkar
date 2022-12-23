#include "DataFile.h"
#include <iostream>

DataFile::DataFile(string name, string data):AD_File(name)
{
	this->Data = data;
}

bool DataFile::operator==(const DataFile& f) const
{
	return AD_File::operator==(f) && (this->Data == f.Data);
}

void DataFile::cat()
{
	AD_File::cat1();
	cout << this->Data << endl;
}
