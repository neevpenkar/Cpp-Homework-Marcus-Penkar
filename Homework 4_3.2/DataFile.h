#pragma once
#include "AD_File.h"
class DataFile :
    public AD_File
{
    protected:
        string Data;
    public:
        DataFile(string name, string data) /*throw(string)*/;

        /*unsigned*/ int getSize() const { return this->Data.length(); }

        bool operator == (const DataFile& f) const;
};

