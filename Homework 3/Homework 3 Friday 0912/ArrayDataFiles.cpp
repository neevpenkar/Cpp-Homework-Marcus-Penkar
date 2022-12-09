#include "ArrayDataFiles.h"


#include <iostream>
#include <fstream>
#include <string>

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

const DataFile* ArrayDataFiles::bigFile_2()
{
	int index = this->bigFile();
	return this->filePointArr[index];
}

void ArrayDataFiles::readAllFiles(const char* fileName)
{
	ifstream check(fileName);
	if (!check.is_open()) throw(-1);
	check.close();

	string myText;
	char buffer[150];
	ifstream MyReadFile(fileName);

	char timeDate[30];
	char fN[50];
	char Data[150];

	while (getline(MyReadFile, myText)) {
		this->toCharPoint(buffer, myText);

		splitInto3(buffer, (char*)timeDate, (char*)fN, (char*)Data);
		tm temp = makeTimeObj(timeDate);

		DataFile tempFile(fN, Data);
		
		// Time Object needs to be taken care of
		//tempFile.setTime(timeDate); 

		*this += tempFile;
		//cout << fN << ": " << Data << endl;
	}
	MyReadFile.close();
}

unsigned int ArrayDataFiles::getLength()
{
	return this->len;
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
				throw("File Exists");
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

void ArrayDataFiles::toCharPoint(char* dest, string src)
{
	for (int i = 0; i < src.length(); i++)
		dest[i] = src[i];
	dest[src.length()] = 0;
}

void ArrayDataFiles::splitInto2(char* str, char* dst1, char* dst2)
{
	char d1[] = "<d1>";
	char d3[] = "<d3>";

	char* catchDateTime = strstr(str, d1);
	char* catchEndLine = strstr(str, d3);

	memcpy(dst1, str, catchDateTime - str);
	dst1[catchDateTime - str] = 0;

	strcpy(dst2, catchDateTime + sizeof(d1) - 1);
	return;
}

void ArrayDataFiles::secondSplit(char* str, char* dst1, char* dst2)
{
	char d2[] = "<d2>"; char d3[] = "<d3>";
	char* catchFilename = strstr(str, d2);
	memcpy(dst1, str, catchFilename - str);
	dst1[catchFilename - str] = 0;

	char* catchEndLine = strstr(str, d3);
	memcpy(dst2, catchFilename + strlen(d2), catchEndLine - (catchFilename + strlen(d2)));
	dst2[catchEndLine - (catchFilename + strlen(d2))] = 0;
}

void ArrayDataFiles::splitInto3(char* str, char* timeDate, const char* filename, char* data)
{
	char temp[150];
	splitInto2(str, timeDate, temp);
	secondSplit(temp, (char*)filename, data);
}

tm ArrayDataFiles::makeTimeObj(char* time_details)
{
	tm tm;
	char* date = strtok(time_details, " ");
	char* time = strtok(NULL, "\n");
	tm.tm_mday = atoi(strtok(date, "/"));
	tm.tm_mon = atoi(strtok(NULL, "/"));
	tm.tm_year = atoi(strtok(NULL, "/"));
	tm.tm_hour = atoi(strtok(time, ":"));
	tm.tm_min = atoi(strtok(NULL, ":"));
	tm.tm_sec = atoi(strtok(NULL, ":"));
	return tm;
}

void ArrayDataFiles::clearBuf(char* add, int length)
{
	for (int i = 0; i < length; i++) {
		*(add + i) = 'a';
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
