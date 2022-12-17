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

		// Aux
		string FolderName;

	public:
		Folder(string path, string filename);
		Folder();
		Folder(const Folder& folder2) throw(string);
		Folder(const Folder& folder2, string path);
		
		void mkfile(string filename, string data) throw(string);
		//void addFileToArray(DataFile newfile) { *this += newfile; };
		static Folder mainFolder;
		string getFullPath() const;

		// Operators
		void operator+=(DataFile& const newfile) throw (string);
		void operator+=(Folder& const newfolder) throw (string);

		// Operator = needs to be implemented
		const Folder& operator=(const Folder& newfolder);

		// Debug Funcs
		void debugFunc1();
};



//Folder Folder::mainFolder;