#pragma once

#include <cstddef>
#include "IntTypes.h"

namespace IO
{

    class File
    {
    public:
        ~File();
        bool Open(const char *_name);
        void Close();
        bool Read(void *_buff, size_t _bytes) const;
        uSize GetSize() const;
        void * GetNativeHandle() const;
    private:
        void *mHandle = nullptr;
        uSize mSize = 0;
    };
    
}
