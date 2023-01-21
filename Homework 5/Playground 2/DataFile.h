#pragma once
#include "AD_File.h"

class DataFile :
    public AD_File
{
	protected:
		string Data;

	public:
		DataFile(string name, string data);

		virtual bool operator == (const AD_File* ptr) const;
		virtual bool operator == (const DataFile& file) const;
		virtual void printInfo() const;

		void debug1() const;


		// Test Features
		virtual void addFileToArray(const AD_File* ptr);
};

