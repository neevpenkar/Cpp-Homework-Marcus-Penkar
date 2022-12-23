#pragma once
#include "AD_File.h"
#include "DataFile.h"

class Folder;
class DataFile;

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

        Folder& operator += (const DataFile& file) throw(string);
        Folder& operator += (const Folder& fold) throw(string);

        string getFullPath() const;
        void dir() const;
        void cat() const;

        ~Folder();

        // Debuging
        void debugFunc1()const;
};