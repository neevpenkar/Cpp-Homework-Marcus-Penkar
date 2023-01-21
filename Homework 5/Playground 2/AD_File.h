#pragma once
#include <iostream>
using namespace std;

#define Equals(a, b) (!strcmp(a,b))
#define type(a) (typeid(a).name())
#define typeEquals(a, b) Equals(type(a), type(b))
#define ifFalse(a) if(!(a))

class AD_File
{
	protected:
		string Name;

	public:
		AD_File(string newname);

		
		virtual ~AD_File() {}

		virtual bool operator == (const AD_File* ptr) const;

		virtual void printInfo() const;


		//virtual ~AD_File();
		// Test Features
		virtual void addFileToArray (const AD_File* ptr) = 0;
};

