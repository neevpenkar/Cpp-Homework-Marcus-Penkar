#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>

#define CONSOLECLEAR cin.clear(); \
					cin.ignore(INT_MAX, '\n');
class DataFile
{
	private:
		char* fileName;
		tm* lastUpdateTime;
		char* data;

	public:
		// Take care of the following sentence
		// **יש לאפשר גישה למתודות המחלקה מחוץ למחלקה למעט המתודה getSize

		DataFile(const char* newName, const char* newData);
		DataFile();
		DataFile(DataFile& copiedObj);

		void setFileName(const char* newname);
		void setTime();
		void setData(const char* newdata);

		char* getTime() const;
		char* getFileName() const;

		long getSize();
		void dir();

		~DataFile();
};