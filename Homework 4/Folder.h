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
		//Folder homeFolder;
	public:
		Folder(string path, string filename);

		string getFullPath() const;
};

