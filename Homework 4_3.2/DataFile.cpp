#include "DataFile.h"

DataFile::DataFile(string name, string data):AD_File(name)
{
	this->Data = data;
}

bool DataFile::operator==(const DataFile& f) const
{
	return AD_File::operator==(f) && (this->Data == f.Data);
}
