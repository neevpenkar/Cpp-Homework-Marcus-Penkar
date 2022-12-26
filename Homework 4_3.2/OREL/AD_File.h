#pragma once

#include <string>
using namespace std;

class AD_File
{
	protected:
		string Name;
		tm* lastUpdateTime;

	public:
		AD_File(string name) throw(string);

		void setTime();
		void setName(string name) throw(string);

		string getTime() const;
		string getName() const { return this->Name; }

		bool operator == (const AD_File& file) const;
		void operator = (const AD_File& file);
		//friend void Folder::operator+=(const DataFile& file) throw(string);
		void cat1() const;
		void cat2()const;

		friend class Folder;
};

