#include "Folder.h"

Folder::Folder(string name, string path):AD_File(name), Path(path)
{
	this->arr = nullptr;
	this->arrLength = 0;
}

bool Folder::operator==(const AD_File* ptr) const
{
	ifFalse(typeEquals(*this, *ptr)) return false;
	ifFalse(this->AD_File::operator==(ptr)) return false;

	const Folder* temp = dynamic_cast<const Folder*>(ptr);
	return temp->Path == this->Path;
}

Folder& Folder::operator=(const Folder& fold)
{
	this->AD_File::operator=(fold);
	
	for (int i = 0; i < this->arrLength; i++)
		delete this->arr[i];
	delete[] this->arr;

	this->arr = new AD_File * [fold.arrLength];

	for (int i = 0; i < fold.arrLength; i++) {
		if (typeEquals(*fold.arr[i], DataFile)) {
			this->arr[i] = new DataFile("", "");
			*this->arr[i] = *fold.arr[i];
			
			// Debug function
			//cout << type(*this->arr[i]) << endl;
		}
		else if (typeEquals(*fold.arr[i], Folder)) {
			Folder* target = dynamic_cast<Folder*>(fold.arr[i]);
			this->arr[i] = new Folder(target->Name, target->Path);
		}
	}
	this->arrLength = fold.arrLength;
	return *this;
}


Folder& Folder::operator+=(const AD_File& newobject) throw(string)
{
	if (typeEquals(newobject, AD_File)) throw(string("AD_File cannot be added to array"));

	AD_File** temp;
	temp = new AD_File * [this->arrLength + 1];

	for (int i = 0; i < this->arrLength; i++) {
		// // Check whether file/folder already exists!

		if (typeEquals(*(this->arr[i]), DataFile)) {
			temp[i] = new DataFile("", "");
			*temp[i] = *this->arr[i];
		}
		else if (type(*(this->arr[i]), Folder)) {
			temp[i] = new Folder("", "");
			*temp[i] = *this->arr[i];
		}
	}

	if (typeEquals(newobject, DataFile)) {
		temp[this->arrLength] = new DataFile("", "");
		*temp[this->arrLength] = newobject;
	}
	else if (typeEquals(newobject, Folder)) {
		temp[this->arrLength] = new Folder("", "");
		*temp[this->arrLength] = newobject;
	}
	else {
		throw(string("Watt U doing? Sending me no datafile no Folder"));
	}

	for (int i = 0; i < this->arrLength; i++)
		delete this->arr[i];
	delete[] this->arr;

	this->arr = temp;
	this->arrLength += 1;

	return *this;
}

void Folder::printInfo() const
{
	this->AD_File::printInfo();
	cout << this->Path << "\n";

	cout << "\n";
	debug2();
	cout << "\n";
}

void Folder::debug1() const
{
	cout << this->Name << " " << this->Path << endl;
}

void Folder::debug2() const
{
	for (int i = 0; i < this->arrLength; i++) {
		cout << type(*this->arr[i]) << endl;
	}
}
