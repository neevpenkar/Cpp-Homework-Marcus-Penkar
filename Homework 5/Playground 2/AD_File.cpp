#include "AD_File.h"

AD_File::AD_File(string name):Name(name)
{
}

void AD_File::printInfo() const
{
	cout << "Name: " << this->Name << endl;
}

bool AD_File::operator==(const AD_File* baseptr) const
{
	return this->Name == baseptr->Name;
}

void AD_File::operator=(const AD_File* ptr) throw(string)
{
	this->Name = ptr->Name;
}
