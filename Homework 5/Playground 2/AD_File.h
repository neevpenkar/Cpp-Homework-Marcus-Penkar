#pragma once
#include <iostream>

using namespace std;

#define Equals(a, b) (!strcmp(a,b))
#define type(a) (typeid(a).name())
#define typeEquals(a, b) Equals(type(a), type(b))
#define ifFalse(a) if(!(a))
#define Son(type, ptr) (dynamic_cast<type>(ptr))

class AD_File
{
	protected:
		string Name;

	public:
		AD_File(string name);

		string getName() const { return this->Name; }
		virtual void printInfo() const;

		virtual bool operator == (const AD_File* baseptr) const;
		virtual void operator += (const AD_File* ptr) throw(string) = 0;
		virtual void operator = (const AD_File* ptr) throw(string);

		virtual ~AD_File() {};
};