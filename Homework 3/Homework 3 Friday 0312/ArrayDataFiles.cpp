#include "ArrayDataFiles.h"

// רצוי שורת פקודה אבל כרגע לא אתעסק עם זה
ArrayDataFiles::ArrayDataFiles()
{
	this->filePointArr =  NULL;
	this->len = 0;
}

ArrayDataFiles::ArrayDataFiles(const ArrayDataFiles& arr)
{
	// Delete (Free earlier data)
	for (int i = 0; i < this->len; i++) delete this->filePointArr[i];
	delete [] this->filePointArr;

	// Reallocate earlier data (field, not the data)
	this->filePointArr = new DataFile * [arr.len];
	this->len = arr.len;

	DataFile** t1 = arr.filePointArr;
	DataFile** t2 = this->filePointArr;

	for (int j = 0; j < arr.len; j++) {
		t2[j] = new DataFile;
		*t2[j] = *t1[j];
	}
}

int ArrayDataFiles::bigFile()
{
	int maxindex = 0;
	for (int i = 1; i < this->len; i++)
	{
		if (*(this->filePointArr[i]) > *(this->filePointArr[maxindex]))
			maxindex = i;
	}
	return maxindex;
}

const ArrayDataFiles& ArrayDataFiles::operator=(const ArrayDataFiles& newarr)
{
	this->len = newarr.len;
	for (int i = 0; i < newarr.len; i++) {
		this->filePointArr[i] = newarr.filePointArr[i];
	}
	// // O: insert return statement here
	return *this;
}

void ArrayDataFiles::operator+=(const DataFile newfile)
{
	if (this->len == 0) {
		this->len++;
		this->filePointArr = new DataFile*;
		this->filePointArr[0] = new DataFile;
		*(this->filePointArr[0]) = newfile;
	}
	else {
		
		// Check if the file already exists
		for (int n = 0; n < this->len; n++)
			if (*(this->filePointArr[n]) == newfile) {
				cout << "File Already exists!" << endl;
				return;
			}
		
		// Store current array in a different array time being
		ArrayDataFiles temp = *this;
		
		// Delete current (inner and outer) pointers
		for (int i = 0; i < temp.len; i++) delete this->filePointArr[i];
		delete[] this->filePointArr;
		
		// Reallocate inner pointers, for all items in temp and also one extra
		this->filePointArr = new DataFile * [temp.len + 1];
		this->len = temp.len + 1;
		
		// Copy all items in temp back to current obj (*this)
		// After allocating an object for all but one inner pointer
		for (int i = 0; i < temp.len; i++)
		{
			this->filePointArr[i] = new DataFile;
			*(this->filePointArr[i]) = *(temp.filePointArr[i]);

		}
		
		// Add new item, after init
		this->filePointArr[temp.len] = new DataFile;
		*(this->filePointArr[temp.len]) = newfile;
	}
}

//const ArrayDataFiles& ArrayDataFiles::operator+=(const DataFile newfile)
//{
//	if (this->len == 0) {
//		this->len++;
//		this->filePointArr = new DataFile*;
//		this->filePointArr[0] = new DataFile;
//		*(this->filePointArr[0]) = newfile;
//	}
//	else {
//
//		// Check if the file already exists
//		for (int n = 0; n < this->len; n++)
//			if (*(this->filePointArr[n]) == newfile) {
//				cout << "File Already exists!" << endl;
//				return *this;
//			}
//
//		// Store current array in a different array time being
//		ArrayDataFiles temp = *this;
//
//		// Delete current (inner and outer) pointers
//		for (int i = 0; i < temp.len; i++) delete this->filePointArr[i];
//		delete[] this->filePointArr;
//
//		// Reallocate inner pointers, for all items in temp and also one extra
//		this->filePointArr = new DataFile * [temp.len + 1];
//		this->len = temp.len + 1;
//
//		// Copy all items in temp back to current obj (*this)
//		// After allocating an object for all but one inner pointer
//		for (int i = 0; i < temp.len; i++)
//		{
//			this->filePointArr[i] = new DataFile;
//			*(this->filePointArr[i]) = *(temp.filePointArr[i]);
//		}
//
//		// Add new item, after init
//		this->filePointArr[temp.len] = new DataFile;
//		*(this->filePointArr[temp.len]) = newfile;
//	}
//
//	return *this;
//}


int ArrayDataFiles::contains(DataFile file)
{
	for (int i = 0; i < this->len; i++) {
		if (*(this->filePointArr[i]) == file)
			return i;
	}
	return -1;
}

void ArrayDataFiles::debugFunc()
{
	for (int i = 0; i < this->len; i++)
		this->filePointArr[i]->dir();
}

ArrayDataFiles::~ArrayDataFiles()
{
	for (int i = 0; i < this->len; i++) delete this->filePointArr[i];
	delete[] this->filePointArr;
}
