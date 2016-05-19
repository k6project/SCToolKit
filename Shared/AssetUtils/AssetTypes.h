#pragma once

#include "AssetFlags.h"
#include "Platform/IntTypes.h"

class Asset
{

public:

    virtual ~Asset();

    virtual AssetFlags GetTypeFlag() const = 0;

    uint8 *Buffer = nullptr;

    uSize NumBytes = 0;

    uint32 Flags = 0;

};

class TextureAsset : public Asset
{

public:

    static AssetFlags TypeFlag;

    bool Init(uint8 *_src, uSize _len, uint8 *_buff, uSize _max);

    virtual AssetFlags GetTypeFlag() const override;

    uint32 Width = 0, Height = 0;

};
