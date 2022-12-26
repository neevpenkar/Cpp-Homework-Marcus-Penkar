#include "DataFile.h"
#include <iostream>
#include <iomanip>
#include <math.h>

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
	//cout << dye::red(temp);
	cout << std::setprecision(1) << (this->getSize() / 1024.0) << " ";
	cout << "KB" << endl;
}
