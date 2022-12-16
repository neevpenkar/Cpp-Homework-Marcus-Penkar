#pragma once
#include <string>

using namespace std;
class AD_File
{
	protected:
		string Filename;
		tm* lastUpdateTime;

	public:
		AD_File(string newname="");

		void setFilename(string newname) throw(string);
		void setTime();

		// For security purposes, a copy of Filename is returned
		// A reference may be needed in the future to Filename
		string getFilename() const { return this->Filename; }

		bool operator == (AD_File& const secondFile) const;
		string getTime() const;
};

