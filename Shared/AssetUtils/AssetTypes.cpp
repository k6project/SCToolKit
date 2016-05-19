#include "AssetTypes.h"
#include "Platform/Memory.h"

AssetFlags TextureAsset::TypeFlag = ASSET_TEXTURE;

Asset::~Asset()
{
    if ((Flags & ASSET_OWNMEM) == ASSET_OWNMEM && Buffer != nullptr)
    {
        MEM::Free(Buffer);
        NumBytes = 0;
        Buffer = nullptr;
    }
    Flags = 0;
}

bool TextureAsset::Init(uint8 *_src, uSize _len, uint8 *_buff, uSize _max)
{
    bool retVal = false;
    if (_src[0] == 37 && _src[1] == 99 && _src[2] == 51)
    {
        _src = _src + 4 + _src[3];
        Width = *((uint32 *)(_src + 0));
        Height = *((uint32 *)(_src + 4));
        Flags = *((uint32 *)(_src + 8));
#ifndef WITH_EDITOR
        //Decompress PNG using libpng
        //use flags to allocate memory
#else
        //Keep PNG as is for texture tool
        NumBytes = *((uint32 *)(_src + 12));
        Buffer = MEM::Ensure(NumBytes, _buff, _max);
        if (Buffer != _buff)
        {
            Flags |= ASSET_OWNMEM;
        }
        MEM::Copy(Buffer, _src + 16, NumBytes);
#endif
        Flags |= ASSET_VALID;
        retVal = true;
    }
    return retVal;
}

AssetFlags TextureAsset::GetTypeFlag() const
{
    return TextureAsset::TypeFlag;
}
