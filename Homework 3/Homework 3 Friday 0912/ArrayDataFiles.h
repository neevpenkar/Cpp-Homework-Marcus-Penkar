#pragma once
#include "DataFile.h"


class ArrayDataFiles
{
	public:
		DataFile** filePointArr;
		unsigned int len = 0;
	//public:
		ArrayDataFiles();
		ArrayDataFiles(const ArrayDataFiles& arr);

		// Methods
		int bigFile();
		const DataFile* bigFile_2();
		void readAllFiles(const char* fileName);
		unsigned int getLength();

		// Operators
		const ArrayDataFiles& operator = (const ArrayDataFiles& newarr);
		void operator += (const DataFile newfile);
		
		static void toCharPoint(char* dest, string src);
		static void splitInto2(char* str, char* dst1, char* dst2);
		static void secondSplit(char* str, char* dst1, char* dst2);
		static void splitInto3(char* str, char* timeDate, const char* filename, char* data);
		static tm makeTimeObj(char* time_details);
		static void clearBuf(char* add, int length);

		// Debug method
		int contains(DataFile file);
		void debugFunc();
		//void debugFunc2();

		~ArrayDataFiles();
		friend class Folder;
		friend ostream& operator << (ostream& out, Folder const& folder);
};

