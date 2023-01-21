#include "DataFile.h"

DataFile::DataFile(string name, string data):AD_File(name)
{
	this->Data = data;
}

void DataFile::printInfo() const
{
	this->AD_File::printInfo();
	cout << "Data: " << this->Data <<  endl;
}

bool DataFile::operator==(const AD_File* baseptr) const
{
	// Check if *baseptr is of type DataFile, else no point in entering body
	ifFalse(typeEquals(*baseptr, DataFile)) return false;

	// Check if datafile1 == datafile2. Dynamic cast should succeed
	if (this->AD_File::operator==(baseptr) == false) return false;
	DataFile* temp = dynamic_cast<DataFile*>((AD_File*)baseptr);
	return temp->Data == this->Data;
}

void DataFile::operator=(const AD_File* ptr) throw(string)
{
	try {
		this->AD_File::operator=(ptr);
		
		DataFile* temp = dynamic_cast<DataFile*>((AD_File*)ptr);
		this->Data = temp->Data;
	}
	catch (string er) {
		throw(er);
	}
}
