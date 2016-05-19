#include "Memory.h"

namespace MEM
{

    void Free(void *_mem)
    {
        free(_mem);
    }

    uint8 * Ensure(uSize _req, uint8 *_mem, uSize &_inoutMax)
    {
        uint8 *out = _mem;
        if (_mem == nullptr || _inoutMax < _req)
        {
            out = Alloc(_req);
            _inoutMax = (out) ? _req : 0;
        }
        return out;
    }

    void * Copy(void *_dst, const void *_src, uSize _size)
    {
        return memcpy(_dst, _src, _size);
    }

}
