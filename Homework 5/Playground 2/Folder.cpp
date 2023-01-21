#include "Folder.h"

Folder Folder::Root("root", "");

Folder::Folder(string name, string path):AD_File(name), Path(path)
{
	this->arr = nullptr;
	this->arrLength = 0;
}

Folder::Folder(const Folder& fold, string path):AD_File(fold)
{
	this->Path = path;

	for (int i = 0; i < this->arrLength; i++)
		delete this->arr[i];
	delete[] this->arr;

	this->arrLength = 0;
	this->arr = new AD_File * [fold.arrLength];
	for (int i = 0; i < fold.arrLength; i++) {
		*this += fold[i];
	}
	cout << "Copy Constructor" << endl;
}

Folder::Folder(const Folder& fold):AD_File(fold)
{
	throw(string("Wrong Copy constructor"));
}

AD_File* Folder::cd(string path) const throw(string)
{
	try {
		return ChangeD(&Folder::Root, path + '\\');
	}
	catch (string er) {
		cout << er << endl;
		throw(er);
	}
}

AD_File* Folder::ChangeD(Folder* root, string path) throw(string)
{
	if (getCurrentPane(path) == "<End>")
	{
		return root;
	}

	string curr = getCurrentPane(path);

	int temp = root->local_find(curr);
	if (temp == -1)
	{
		// Case (3/3): Folder not found
		throw(string("folder not found"));
	}

	else
	{
		Folder* TMP = dynamic_cast<Folder*>((*root)[temp]);
		if (TMP)
		{
			try
			{
				return ChangeD(TMP, getNextPane(path));
			}
			catch (string error)
			{
				throw (error);
			}
		}
		else
		{
			throw(string("Path contains a file and not a folder.\n"));
		}
	}
}


bool Folder::operator%(const AD_File* ptr) const
{
	ifFalse(typeEquals(*ptr, Folder)) return false;
	Folder* fold = dynamic_cast<Folder*>((AD_File*)ptr);
	return (this->Name == fold->Name) && (this->Path == fold->Path);
}

AD_File* Folder::operator[](const int index) const throw(string)
{
	if (index < 0) throw("Incorrect Index");
	
	return this->arr[index];
}

int Folder::local_find(string name) const
{
	// Cannot assume that AD_File ptr is of one type only, both Df and Fl are possible
	for (int i = 0; i < this->arrLength; i++)
		if (this->arr[i]->getName() == name) return i;
	return -1;
}

void Folder::operator+=(const AD_File* newobject) throw(string)
{
	//if (typeEquals(*newobject, AD_File)) throw(string("AD_File cannot be added to array"));

	// First time init
	if (this->arrLength == 0) {
		this->arr = new AD_File* [1];

		if (typeEquals(*newobject, DataFile)) {
			const DataFile* tmp = dynamic_cast<const DataFile*> (newobject);
			*this->arr = new DataFile(tmp->getName(), tmp->getData());
		}
		else if (typeEquals(*newobject, Folder)) {
			const Folder* tmp = dynamic_cast<const Folder*> (newobject);
			*this->arr = new Folder(tmp->getName(), tmp->getFullPath() + '\\');
		}
		this->arrLength = 1;
		return;
	}

	AD_File** temp;
	temp = new AD_File * [this->arrLength + 1];

	for (int i = 0; i < this->arrLength; i++) {
		// // Check whether file/folder already exists!
		
		if (typeEquals(*(this->arr[i]), Folder)) {
			const Folder* tmp = dynamic_cast<const Folder*> (this->arr[i]);
			temp[i] = new Folder(tmp->getName(), tmp->Path);
		}
		else if (typeEquals(*(this->arr[i]), DataFile)) {
			const DataFile* tmp = dynamic_cast<const DataFile*> (this->arr[i]);
			temp[i] = new DataFile(tmp->getName(), tmp->getData());
		}
	}

	if (typeEquals(*newobject, DataFile)) {
		const DataFile* tmp = dynamic_cast<const DataFile*> (newobject);
		temp[this->arrLength] = new DataFile(tmp->getName(), tmp->getData());
	}
	else if (typeEquals(*newobject, Folder)) {
		const Folder* tmp = dynamic_cast<const Folder*> (newobject);
		temp[this->arrLength] = new DataFile(tmp->getName(), tmp->getFullPath() + '\\');
	}
	else {
		throw(string("Watt U doing? Sending me no datafile no Folder"));
	}

	for (int i = 0; i < this->arrLength; i++)
		delete this->arr[i];
	delete[] this->arr;

	this->arr = temp;
	temp = nullptr;
	this->arrLength += 1;

	return;
}

bool Folder::operator==(const AD_File* baseptr) const
{
	// Check if *baseptr is of type Folder, else no point in entering body
	ifFalse(typeEquals(*baseptr, Folder)) return false;

	// Cast and then
	Folder* folder = dynamic_cast<Folder*>((AD_File*)baseptr);
	
	// Check other stuff
	// Start with the lengths
	if (this->arrLength != folder->arrLength) return false;

	// Go over each array in this and check if name and path are the same for "Folders"!!!
	for (int i = 0; i < this->arrLength; i++) {
		bool check = false;
		for (int j = 0; j < this->arrLength; j++) {
			if (folder[i] % this->arr[j]) check = true;
		}
		if (check == false) return false;
	}
	return (this->Path == folder->Path) && AD_File::operator==(baseptr);
}

void Folder::operator=(const AD_File* ptr) throw(string)
{
	try {
		this->AD_File::operator=(ptr);
	}
	catch (string er) {
		throw(er);
	}

	Folder* temp = dynamic_cast<Folder*>((AD_File*)ptr);
	this->Path = temp->Path;

	// Free existing memory
	for (int i = 0; i < this->arrLength; i++)
		delete this->arr[i];
	delete[] this->arr;

	// Reallocate memory with new objects size
	this->arr = new AD_File * [temp->arrLength];
	for (int i = 0; i < temp->arrLength; i++) {
		if (typeEquals(*temp->arr[i], DataFile)) {
			this->arr[i] = new DataFile("", "");
			*this->arr[i] = *temp->arr[i];
		}
		else if (typeEquals(*temp->arr[i], Folder)) {
			Folder* target = dynamic_cast<Folder*>(temp->arr[i]);
			this->arr[i] = new Folder(target->Name, target->Path);
			// Copy path and name only or the whole tree of the folder?
		}
	}
	this->arrLength = temp->arrLength;
}

void Folder::mkfile(string name, string data) throw(string)
{
	// Need to hceck that file does not exist already
	DataFile temp(name, data);
	try {
		//*this += &temp;
		this->Folder::operator+=(&temp);
	}
	catch (string er) {
		throw(er);
	}
}

void Folder::printInfo() const
{
	this->AD_File::printInfo();
	cout << "Path: " << this->Path << endl;

	for (int i = 0; i < this->arrLength; i++) {
		cout << i << ": " << this->arr[i]->getName() << endl;
		//cout << "  Path: " << this->Path << endl;
	}
}

Folder::~Folder()
{
	for (int i = 0; i < this->arrLength; i++)
		delete this->arr[i];
	delete[] this->arr;
}

void Folder::debugFunc1()
{
	for (int i = 0; i < this->arrLength; i++) {
		if (typeEquals(*this->arr[i], Folder)) {
			
			cout << Son(Folder*, this->arr[i])->getFullPath() << endl;
		}
		else if (typeEquals(*this->arr[i], DataFile)) {
			cout << Son(DataFile*, this->arr[i])->getData() << endl;
		}
	}
}

Folder Folder::debugFunc2()
{
	// Test Function for copy constructor
	Folder temp("Copy Construct Test", "C:");

	//Folder t1 = Folder("Internal test1", "deq");
	//Folder t2 = Folder("Internal test2", "deq");
	Folder t1 ("Internal test1", "deq");
	Folder t2 ("Internal test2", "deq");
	DataFile tf3 ("InternalTest3_File", "stam data");

	temp += &t1;
	temp += &t2;
	temp += &tf3;
	
	return Folder(temp, "Copy test path");
}

string Folder::getCurrentPane(string path)
{
	const static char token = '\\';
	if (path.find(token) == -1) return string("<End>");
	return path.substr(0, path.find(token));
}

string Folder::getNextPane(string path)
{
	const static char token = '\\';
	if (path.find(token) == -1) return path;
	return path.substr(path.find(token) + 1, path.length());
}

