#include "DataFile.h"

DataFile::DataFile(string name, string data):AD_File(name), Data(data)
{
}

bool DataFile::operator==(const AD_File* ptr) const
{
	ifFalse(typeEquals(*this, *ptr)) return false;
	ifFalse(this->AD_File::operator==(ptr)) return false;

	const DataFile* temp = dynamic_cast<const DataFile*>(ptr);
	return temp->Data == this->Data;
}

bool DataFile::operator==(const DataFile& file) const
{
	// Temp
	return this->Data == file.Data;
}

void DataFile::printInfo() const
{
	this->AD_File::printInfo();
	cout << this->Data << "\n";
}

void DataFile::debug1() const
{
	cout << this->Name << " " << this->Data << endl;
}

void DataFile::addFileToArray(const AD_File* ptr)
{
	return;
}

