#pragma once
#include <string>
#include "AD_File.h"
#include "DataFile.h"
using namespace std;

class Folder:public DataFile
{
	private:
		DataFile** fileArray;
		Folder** folderArray;
		// Unsigned int but it will lengthen things
		int fileArrSize;
		int folderArrSize;

		string Path;

	public:
		Folder(string path, string filename);
		static Folder mainFolder;
		string getFullPath() const;

		// Operators
		void operator+=(DataFile& const newfile); //:throw(string);


		// Debug Funcs
		void debugFunc1();
};



//Folder Folder::mainFolder;