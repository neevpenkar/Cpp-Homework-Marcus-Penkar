#include "DataFile.h"
#include <cstring>
#include <iostream>

using namespace std;

int DataFile::fileCounter = 0;
int DataFile::fileInitNum = 1;


char* DataFile::getFileName() const
{
	return this->fileName;
}

char* DataFile::getData() const
{
	return this->data;
}

tm* DataFile::getTimeObj() const
{
	return this->lastUpdated;
}

DataFile::DataFile(const char* newname, const char* newdata)
{
	this->setFileName(newname);
	this->setData(newdata);
	this->setTime();

	this->fileCounter++;
}

DataFile::DataFile()
{
	char defaultName[20 + 5] = "sampleFile";
	int temp = this->fileInitNum; // 1

	while (temp) {
		char tempS[3];
		_itoa(temp % 10, tempS, 10);
		strcat(defaultName, tempS);
		temp /= 10;
	}

	char defaultExt[] = ".npgm";
	char defaultData[] = "Yo!";
	strcat(defaultName, defaultExt);

	this->setFileName(defaultName);
	this->setData(defaultData);
	this->setTime();

	this->fileInitNum++;
	this->fileCounter++; // Will need to be removed if two args constructor is fixed and used
}

DataFile::DataFile(const DataFile& copiedObj)
{
	this->setFileName(copiedObj.getFileName());
	this->setData(copiedObj.getData());
	this->setTimeManually(copiedObj.getTimeObj());
}

void DataFile::setData(const char* newdata)
{
	int length = strlen(newdata);
	this->data = new char[length + 1];
	strcpy(this->data, newdata);
}

void DataFile::editData(const char* newdata)
{
	delete[] data;
	this->setTime();
	this->setData(newdata);
}

void DataFile::setFileName(const char* newname)
{
	// Allocate an *important* buffer, copy newname into it
	bool status = checkString(newname);
	char buffer[50];
	strcpy(buffer, newname);

	// Check for prohibited chars
	// If found, get another filename from user
	while (status) {
		cout << "Enter filename once more, correctly: " << endl;
		CONSOLECLEAR
			gets_s(buffer, 49);
		status = checkString(buffer);
	}

	this->fileName = new char[strlen(buffer) + 1];
	strcpy(this->fileName, buffer);
}

void DataFile::dir() const
{
	cout << this->getFileName() << "\t";
	cout << this->getData() << "\t";

	char* t = this->getTime();
	cout << t << endl;

	delete[] t;
}

void DataFile::setTimeManually(tm* add)
{
	this->lastUpdated = add;
}

const DataFile& DataFile::operator=(const DataFile& newfile)
{
	DataFile temp(newfile.getFileName(), newfile.getData());
	return temp;
}

bool DataFile::operator==(DataFile const& fileB)
{
	bool i = strcmp(this->fileName, fileB.fileName);
	bool j = strcmp(this->data, fileB.data);
	return (!i) * (!j);
}

bool DataFile::operator>(DataFile const& fileB)
{
	return strlen(this->getData()) > strlen(fileB.getData());
}

bool DataFile::operator<(DataFile const& fileB)
{
	return strlen(this->getData()) < strlen(fileB.getData());
}

DataFile::~DataFile()
{
	delete[] this->data;
	delete[] this->fileName;
	this->fileCounter--;
	//delete[] this->
}

void DataFile::setTime()
{
	// current date/time based on current system
	time_t now = time(0);
	this->lastUpdated = localtime(&now);
}
//void DataFile::setTime()
//{
//	// current date/time based on current system
//	time_t t1 = time(0);
//	struct tm* now = localtime(&t1);
//	this->lastUpdated = *now;
//}

char* DataFile::getTime() const
{
	// Possible data leak - there seems to be no option of freeing stringTime
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", this->lastUpdated);

	char* stringTime = new char[strlen(buf) + 1];
	strcpy(stringTime, buf);
	return stringTime;
}

ostream& operator<<(ostream& os, DataFile const& file)
{
	os << file.getFileName() << "\t";
	os << file.getData() << "\t";

	char* t = file.getTime();
	os << t << endl;
	delete[] t;

	return os;
}

// Auxilary Func Defs
bool checkString(const char* str) {
	// Will check if prohibited chars are in str
	// Will return true if contains prob, false otherwise

	char prohibited[] = { '>' ,'?' ,'*' ,':' ,'/' ,'\\', '|' ,'<' };

	// For every letter in str, I will compare to each ascii in prohibted chars array;
	// If after both the loops finish, safe to say there is no prob;

	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < sizeof(prohibited); j++)
			if (str[i] == prohibited[j]) return true;
	}
	return false;
}