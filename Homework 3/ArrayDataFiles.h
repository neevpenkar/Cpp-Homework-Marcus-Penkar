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

		// Operators
		const ArrayDataFiles& operator = (const ArrayDataFiles& newarr);
		const ArrayDataFiles& operator += (const DataFile newfile);
		
		
		~ArrayDataFiles();
};

