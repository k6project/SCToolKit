#include "IO.h"

#include <cstdio>

namespace IO
{
    
    File::~File()
    {
        Close();
    }
    
    bool File::Open(const char *_name)
    {
        bool retVal = false;
        FILE *file = nullptr;
        if ((file = fopen(_name, "rb")))
        {
            fseek(file, 0, SEEK_END);
            mSize = ftell(file);
            fseek(file, 0, SEEK_SET);
            mHandle = file;
            retVal = true;
        }
        return retVal;
    }
    
    void File::Close()
    {
        if (mHandle != nullptr)
        {
            fclose((FILE *)mHandle);
            mHandle = nullptr;
            mSize = 0;
        }
    }
    
    bool File::Read(void *_buff, size_t _bytes) const
    {
        size_t num = fread(_buff, 1, _bytes, (FILE *)mHandle);
        return (num == _bytes);
    }
    
    uSize File::GetSize() const
    {
        return mSize;
    }
    
    void * File::GetNativeHandle() const
    {
        return mHandle;
    }
    
}
