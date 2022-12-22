#pragma once
#include "AD_File.h"
#include "DataFile.h"
class Folder;

typedef struct folderArray {
    Folder** arr;
    int length;
} folderArray;

typedef struct fileArray {
    DataFile** arr;
    int length;
} fileArray;

class Folder :
    public AD_File
{
    protected:
        folderArray tikiot;
        fileArray kvazim;
        
        string Path;
    public:
        static Folder Root;

        Folder(string foldername, string path);
        Folder(const Folder& fol) throw(string);

        void operator += (const DataFile& file) throw(string);

        string getFullPath() const;
};

