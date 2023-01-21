#pragma once
#include "AD_File.h"
//class DataFile;
#include "DataFile.h"

class Folder :
    public AD_File
{
	protected:
		string Path;

		AD_File** arr;
		int arrLength;

	public:
		Folder(string name, string path);

		// Part 1 Operator ==
		virtual bool operator == (const AD_File* ptr) const;

		virtual Folder& operator = (const Folder& fold);
		//Folder operator = (const Folder& folder) throw(string);

		Folder& operator += (const AD_File& newobject) throw(string);
		virtual void printInfo() const;

		void debug1()const;
		void debug2() const;



		virtual void addFileToArray(const AD_File* ptr) { *this += *ptr;}
};

