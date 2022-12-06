#pragma once
#include "DataFile.h"

class ArrayDataFiles
{
	private:
		DataFile** filePointArr;
		unsigned int len = 0;
	public:
		ArrayDataFiles();
		ArrayDataFiles(const ArrayDataFiles& arr);

		// Methods
		int bigFile();
		void readAllFiles(const char* fileName);

		// Operators
		const ArrayDataFiles& operator = (const ArrayDataFiles& newarr);
		//const ArrayDataFiles& operator += (const DataFile newfile);
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
};

