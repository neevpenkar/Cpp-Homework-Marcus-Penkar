#define _CRT_SECURE_NO_WARNINGS
#include "AD_File.h"
#include <string>
#include <iostream>

using namespace std;

AD_File::AD_File(string newname)
{
	try {
		this->setFilename(newname);
		this->setTime();
	}
	catch (string ermsg) {
		throw ermsg;
	}
}

void AD_File::setFilename(string newname) throw(string)
{
	char prohibited[] = "/\\*<?>:";
	string msg = "Prohibited Chars Used";

	for (int i = 0; i < newname.length(); i++)
		for (int j = 0; j < sizeof(prohibited); j++)
			if (newname[i] == prohibited[j])
				throw msg;
	this->Filename = newname;
}

// Time funcs
void AD_File::setTime()
{
	time_t now = time(0);
	lastUpdateTime = localtime(&now);
}

bool AD_File::operator==(AD_File& const secondFile) const
{
	bool a = (this->Filename == secondFile.Filename);
	bool b = (this->getTime() == secondFile.getTime());
	return a && b;
}

string AD_File::getTime() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", this->lastUpdateTime);

	string temp;
	int i = 0;
	while (buf[i]) {
		temp += buf[i]; i++;
	}
	return temp;
}

