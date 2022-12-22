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

		bool operator == (const AD_File& file) const;
};

