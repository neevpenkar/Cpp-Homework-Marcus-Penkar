#pragma once
#include "ArrayDataFiles.h"

#define MAXLENGTH 150
class Folder
{
	private:
		char* folderName;
		ArrayDataFiles fileArray;
		char* path;
	
	public:
		Folder(const char* name, const char* dest);
		Folder(const Folder& newitem);

		//char* getFolderName() { return this->folderName; }
		//char* getPath() { return this->path; }

		void classEditHelper();

		// Debug
		void debugFunc1();

		~Folder();
		
};

