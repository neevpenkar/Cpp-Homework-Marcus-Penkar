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
		
		unsigned int len = 0;

		// Unsigned int but it will lengthen things
		int fileArrSize;
		int folderArrSize;
		
		string Path;
		//Folder homeFolder;
	public:
		static Folder MainFolder;
		//Folder addFileToArray();
		//bool operator ==(const Folder& fol);
		//void operator += (const Folder newfolder);
		//void operator += (const DataFile newfile);
		//const Folder& operator = (const Folder& newfolder);

		Folder(string path, string filename);
		string getFullPath() const;

		
};

Folder Folder::MainFolder("", "root");