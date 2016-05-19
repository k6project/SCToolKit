#pragma once

#include <cstdlib>
#include <cstring>

#include "IntTypes.h"

namespace MEM
{

    void Free(void *_mem);

    template <typename T = uint8>
    T * Alloc(uSize _size, bool _zero = false)
    {
        T *mem = (T*)malloc(_size);
        if (mem && _zero)
        {
            memset(mem, 0, _size);
        }
        return mem;
    }

    uint8 * Ensure(uSize _req, uint8 *_mem, uSize &_inoutMax);

    void * Copy(void *_dst, const void *_src, uSize _size);

}
