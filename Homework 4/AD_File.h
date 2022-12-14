#pragma once
#include <string>

using namespace std;

class AD_File
{
	protected:
		string FileName;
		tm* lastUpdateTime;
	public:
		AD_File(string name);

		void setFileName(string newname) throw(char*);
		void setTime();

		string getFileName() const;
		string getTime() const;

		bool operator == (const AD_File& secondFile);

};

