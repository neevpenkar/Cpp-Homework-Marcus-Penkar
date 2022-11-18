#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

#define CONSOLECLEAR cin.clear(); \
					cin.ignore(INT_MAX, '\n');

class DataFile
{
	private:
		char* fileName;
		char* data;
		tm* lastUpdated;

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

		~DataFile();
};



// Auxilary Funcs
bool checkString(const char* str);

