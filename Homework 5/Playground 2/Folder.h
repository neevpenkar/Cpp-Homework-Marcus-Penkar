#pragma once
#include "AD_File.h"
#include "DataFile.h"

class Folder :
    public AD_File
{
	protected:
		AD_File** arr;
		int arrLength;
		string Path;

	public:
		Folder(string name, string path);
		Folder(const Folder& fold) throw(string);
		Folder(const Folder& fold, string path);

		string getFullPath() const { return (this->Path); }
		AD_File* cd(string path) const throw(string);
		static AD_File* ChangeD(Folder* root, string path) throw(string);
		
		bool operator % (const AD_File* ptr) const;
		void operator += (const AD_File* ptr) const { this->operator+=(ptr); }
		AD_File* operator [] (const int index) const throw(string);
		int local_find(string name) const;

		virtual void operator += (const AD_File* newobject) throw(string);
		virtual bool operator == (const AD_File* baseptr) const;
		virtual void operator = (const AD_File* ptr) throw(string);

		void mkfile(string name, string data) throw (string);

		virtual void printInfo() const;
		~Folder();
		static Folder Root;

		// Debuf Funcs
		void debugFunc1();
		Folder debugFunc2();

		static string getCurrentPane(string path);
		static string getNextPane(string path);
};

