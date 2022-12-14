#define _CRT_SECURE_NO_WARNINGS
#include "AD_File.h"
#include <iostream>


using namespace std;

// This func is not working as expected, may need to write it once again all over
void AD_File::setFileName(string newname) throw(char*)
{
	string ftmp = newname;
	bool check = false;

	while (check == false)
	{
		bool x = true;
		for (int i = 0; i < ftmp.length(); i++)
		{
			if (ftmp[i] == '<' || ftmp[i] == '>' || ftmp[i] == '?' || ftmp[i] == '*' ||
				ftmp[i] == ':' || ftmp[i] == '/' || ftmp[i] == '\\' || ftmp[i] == '|' || ftmp[i] == '\"')
			{
				throw("Prohibited characters used!");
			}
		}
		if (x == true)
		{
			check = true;
		}
	}
	this->FileName = ftmp;
}

AD_File::AD_File(string name)
{
	try {
		this->setFileName(name);
		this->setTime();
	}
	catch (char* erMsg) {
		cout <<"Error: " << erMsg;
		exit(-10);
	}
}

void AD_File::setTime()
{
	// current date/time based on current system
	time_t now = time(0);
	lastUpdateTime = localtime(&now);
}
string AD_File::getTime() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", lastUpdateTime);
	return buf;
}

string AD_File::getFileName() const
{
	return this->FileName;
}

bool AD_File::operator==(const AD_File& secondFile)
{
	bool i = (this->FileName == secondFile.FileName);
	bool j = (this->getTime() == secondFile.getTime());
	
	return i && j;
}

