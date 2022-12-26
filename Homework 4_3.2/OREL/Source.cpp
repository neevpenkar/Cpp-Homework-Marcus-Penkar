#include <iostream>
#include "AD_File.h"
#include "DataFile.h"
#include "Folder.h"

using namespace std;
int main() {
	/*try {
		Folder temp("", "");

		Folder test1("C", "");
		Folder test2("D", "");

		DataFile t1("Neev", "Penkarakfshdgfffiuwgfiwhuofuiegewuuiwegwfiuuwifugwe");
		DataFile t2("Guy", "Marcus");

		(temp.Root += test1) += test2;
		(temp.Root += t1) += t2;
		temp.Root.dir();
	}
	catch (string err) {
		cout << err;
	}*/
	
	Folder temp("Orel", "Shaybet");
	Folder temp3("Neev", " penkar");

	cout << temp.getName() << endl;
	cout << temp3.getName() << endl;

	temp3 = temp;
	cout << temp3.getName() << endl;

	return 0;
}