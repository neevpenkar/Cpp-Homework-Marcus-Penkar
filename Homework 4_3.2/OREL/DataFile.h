#pragma once
#include "AD_File.h"
#include "Folder.h"

class DataFile :
    public AD_File
{
    protected:
        string Data;
    public:
        DataFile(string name, string data) /*throw(string)*/;

        /*unsigned*/ int getSize() const { return this->Data.length(); }

        bool operator == (const DataFile& f) const;
        string getData()const { return this->Data; };
        void cat();

        //friend void Folder::operator+=(const DataFile & file) throw(string);
        friend class Folder;
};

