#include <iostream>
#include "AD_File.h"
#include "Folder.h"
#include "DataFile.h"

using namespace std;

void addFile2Array(AD_File** arr, AD_File* obj);
int main() {

	//AD_File *pt1, *pt2;
	//AD_File* pt3, * pt4;
	//pt1 = new DataFile("file", "abc");
	//pt2 = new DataFile("file", "abc");
	//pt3 = new Folder("123", "abc");
	//pt4 = new Folder("123", "abdc");
	//*((Folder*)pt3) += *pt1;
	//*((Folder*)pt3) += *pt4;
	////(*((Folder*)pt3)).debug2();
	//((Folder*)pt3)->debug2();

	//AD_File** tempArray = nullptr;
	//tempArray = new AD_File * [5];

	//addFile2Array(tempArray, &tempFile1);

	//tempArray[0]->printInfo();
	//delete[] tempArray;

	//Folder tempFolder1("1", "eer");
	//Folder tempFolder2("3", "frfrf");

	//DataFile tempFile1("testFile1", "dqdqi");
	//DataFile tempFile2("testFile2", "dqdqi");

	//tempFolder1 += tempFile1;
	//tempFolder1 += tempFile2;

	//tempFolder2 = tempFolder1;

	//tempFolder2 += tempFolder1;
	////tempFolder2 += tempFolder1;

	//tempFolder1 += tempFolder2;
	//tempFolder2 += tempFolder1;

	//tempFolder2.debug2();


	AD_File* newfold1 = new Folder("tempFolder", "Dde");

	AD_File* newfile1 = new DataFile("temp", "Dde");

	DataFile t("Test Vector", "ded");
	newfold1->addFileToArray( &t );

	/*newfile1->printInfo();*/
	//Folder* temp = dynamic_cast<Folder*>(newfold1);
	newfold1->printInfo();

	return 0;
}

void addFile2Array(AD_File** arr, AD_File* obj) {
	if (typeEquals(*obj, DataFile)) {
		arr[0] = new DataFile("", "");
		*arr[0] = *obj;
	}
	else if (typeEquals(*obj, Folder)) {
		arr[0] = new Folder("", "");
		*arr[0] = *obj;
	}
	else exit(-30);
}