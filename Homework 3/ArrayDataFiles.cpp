#include "ArrayDataFiles.h"

ArrayDataFiles::ArrayDataFiles()
{
	this->filePointArr =  NULL;
	this->len = 0;
}

ArrayDataFiles::ArrayDataFiles(const ArrayDataFiles& arr)
{
	this->filePointArr = new DataFile * [arr.len];

	DataFile** t1 = arr.filePointArr;
	DataFile** t2 = this->filePointArr;

	for (int j = 0; j < arr.len; j++) {
		t2[j] = new DataFile;
		*t2[j] = *t1[j];
	}
}
