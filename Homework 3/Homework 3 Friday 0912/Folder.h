#pragma once
#include "ArrayDataFiles.h"
#include <iostream>
#define MAXLENGTH 150

using namespace std;
class Folder
{
	private:
		char* folderName;
		ArrayDataFiles fileArray;
		char* path;
	
	public:
		Folder(const char* name, const char* dest);
		Folder(const Folder& newitem);

		char* getFolderName() { return this->folderName; }
		char* getPath() { return this->path; }
		ArrayDataFiles& getDataFiles() { return this->fileArray; };
		void readAllFiles();

		// Operators
		const Folder& operator = (const Folder& fol);
		bool operator == (const Folder& fol);
		void operator += (const DataFile newfile);

		friend ostream& operator << (ostream& out, Folder const & folder);

		void classEditHelper();

		// Debug
		void debugFunc1();

		~Folder();
};

