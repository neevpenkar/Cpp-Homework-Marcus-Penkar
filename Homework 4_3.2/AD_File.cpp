#define _CRT_SECURE_NO_WARNINGS
#include "AD_File.h"
#include <iostream>

AD_File::AD_File(string name) throw(string)
{
	try {
		this->setName(name);
		this->setTime();
	}
	catch (string err) {
		throw err;
	}
}

void AD_File::setTime()
{
	time_t now = time(0);
	this->lastUpdateTime = localtime(&now);
}

string AD_File::getTime() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", this->lastUpdateTime);
	return buf;
}

bool AD_File::operator==(const AD_File& file) const
{
	return this->Name == file.Name;
}

void AD_File::setName(string name) throw(string)
{
	char prohibited[] = "/\\*<?>:";
	string msg = "Prohibited Chars Used";

	for (int i = 0; i < name.length(); i++)
		for (int j = 0; j < sizeof(prohibited); j++)
			if (name[i] == prohibited[j])
				throw msg;
	this->Name = name;
}
