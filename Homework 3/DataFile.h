#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

#define CONSOLECLEAR cin.clear(); \
					cin.ignore(INT_MAX, '\n');
using namespace std;
class DataFile
{
private:
	char* fileName;
	char* data;
	tm* lastUpdated;

	static int fileCounter;
	static int fileInitNum;
	//tm lastUpdated;

public:
	char* getFileName()const;
	char* getData()const;
	tm* getTimeObj() const;
	char* getTime() const;


	DataFile(const char* newname, const char* newdata);
	DataFile();
	// Take a second look at the copy constructor
	DataFile(const DataFile& copiedObj);

	void setData(const char* newdata);
	void editData(const char* newdata);
	void setFileName(const char* newname);
	void dir() const;

	void setTime();
	void setTimeManually(tm* add);

	// Operators
	const DataFile& operator = (const DataFile& newfile);
	bool operator == (DataFile const& fileB);
	bool operator > (DataFile const& fileB);
	bool operator < (DataFile const& fileB);
	friend ostream& operator << (ostream& os, DataFile const & file);

	~DataFile();
	int activeFiles() { return fileCounter; };
};



// Auxilary Funcs
bool checkString(const char* str);

