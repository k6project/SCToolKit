#pragma once

#include "Platform/IntTypes.h"

#ifdef WITH_EDITOR
#define ASSET_ID const char *
#else
#define ASSET_ID AssetID
#endif

template <typename AssetType>
bool LoadAsset(ASSET_ID _assetId, AssetType &_out, uint8 *_buff = nullptr, uSize _max = 0);
