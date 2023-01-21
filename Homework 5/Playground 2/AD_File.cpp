#include "AD_File.h"

AD_File::AD_File(string newname)
{
	this->Name = newname;
}

bool AD_File::operator==(const AD_File* ptr) const
{
	return this->Name == ptr->Name;
}

void AD_File::printInfo() const
{
	cout << this->Name << "\t";
}

