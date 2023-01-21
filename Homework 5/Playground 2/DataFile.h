#pragma once
#include "AD_File.h"
class DataFile :
    public AD_File
{
	protected:
		string Data;
	public:
		DataFile(string name, string data);
		string getData() const { return this->Data; }

		virtual void printInfo() const;

		virtual void operator += (const AD_File* ptr) throw(string) { return; }
		virtual bool operator == (const AD_File* baseptr) const;
		virtual void operator = (const AD_File* ptr) throw(string);
};

