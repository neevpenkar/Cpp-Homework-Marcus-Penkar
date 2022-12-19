#pragma once
#include <string>
#include "AD_File.h"
using namespace std;

class DataFile: public AD_File
{
	protected:
		string Data;
	public:
		DataFile(string filename, string data);
		DataFile();

		void setData(string newdata);
		int getSize() const { return this->Data.length(); }

		// For security purposes, a copy of Filename is returned
		// A reference may be needed in the future to Filename
		string getData() const { return this->Data; }

		bool operator == (DataFile& const other);
};

