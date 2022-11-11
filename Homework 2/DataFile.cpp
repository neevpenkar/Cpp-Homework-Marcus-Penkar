#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include <cstring>
#include <iostream>

using namespace std;

void DataFile::setFileName(const char* newname)
{
	// Copying the new name into a local buffer for adaptabilty
	char buffer[100];
	strcpy_s(buffer, 100, newname);
	// Prohibited constants
	char prohibited[9] = "><?/|\\*:";

	// Basically, if newname is okay, the while is skipped
	// If newname(buffer) contains prohibited chars, program will enter the while
	// a new name for file will be accepted into buffer
	// and it will go on till no wring chars appear in buffer
	
	//while (strpbrk(buffer, prohibited) != NULL) {
	//	cout << "Prohibited characters used! \n";
	//	CONSOLECLEAR
	//	gets_s(buffer, 100);
	//}

	// Proof checked buffer is the new name of the file
	fileName = new char[strlen(buffer) + 1];
	strcpy(fileName, buffer);
}

DataFile::DataFile(const char* newName, const char* newData)
{
	setData(newData);
	setTime();
	setFileName(newName);
}

DataFile::DataFile()
{
	char newfilename[80];
	strcpy(newfilename, "file_");

	char buf[20];
	setTime();
	strftime(buf, sizeof(buf), "%d.%m.%Y %X", lastUpdateTime);
	strcat(newfilename, buf);
	
	char something[] = "";
	setFileName(newfilename);
	setData(something);

	//DataFile(newfilename, something); // Seems to be a problem
}

void DataFile::setData(const char* newdata)
{
	data = new char[strlen(newdata) + 1];
	strcpy(data, newdata);
}

DataFile::DataFile(DataFile& obj)
{
	fileName = new char[strlen(obj.fileName) + 1];
	strcpy(fileName, obj.fileName);

	lastUpdateTime = obj.lastUpdateTime;
	//memcpy(&lastUpdateTime, &(obj.lastUpdateTime), sizeof(obj.lastUpdateTime));

	data = new char[strlen(obj.data) + 1];
	strcpy(data, obj.data);
}

char* DataFile::getTime() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", lastUpdateTime);
	char* stringTime = new char[strlen(buf) + 1];
	strcpy(stringTime, buf);
	return stringTime;
}

DataFile::~DataFile()
{
	delete[] fileName;
	delete[] data;
}

long DataFile::getSize()
{
	return (long)strlen(data);
}

void DataFile::dir()
{
	cout << getTime() << (double)(getSize() / 1024) << " KB   " << fileName << endl;
}

char* DataFile::getFileName() const
{
	return fileName;
}

void DataFile::setTime()
{
	// current date/time based on current system
	time_t now = time(0);
	lastUpdateTime = localtime(&now);
}







//void DataFile::setFileName()
//{
//	// "abcdefghijk", '?' -> NULL
//	// "afdakf?", '?' -> newname + 6
//
//	char prohibited[9] = { '>', '?', '*', ':', '/', '|', '<', 92, 0 };
//
//	char buffer[100];
//	gets_s(buffer, 100);
//
//	if (strpbrk(buffer, prohibited) == NULL) {
//		fileName = new char[strlen(buffer) + 1];
//		strcpy(fileName, buffer);
//	}
//	else {
//		cout << "Please do not use '>', '?', '*', ':', '/', '|', '<', \\";
//		setFileName();
//	}
//}