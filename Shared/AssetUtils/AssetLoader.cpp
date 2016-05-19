#include "AssetLoader.h"
#include "AssetFlags.h"
#include "AssetTypes.h"
#include "Platform/IO.h"
#include "Platform/Memory.h"

#ifndef WITH_EDITOR
#include "AssetRegistry.h"
#define GET_ASSET_PATH(id) Assets::GetFilePath(id)
#define CHECK_ASSET_TYPE(id,t) (Assets::GetAssetType(id) == t::TypeFlag)
#else
#define GET_ASSET_PATH(id) id
#define CHECK_ASSET_TYPE(id,t) true
#endif

template <typename AssetType>
bool LoadAsset(ASSET_ID _assetId, AssetType &_asset, uint8 *_buff, uSize _max)
{
    bool retVal = false;
    if (CHECK_ASSET_TYPE(_assetId, AssetType))
    {
        IO::File inFile;
        if (inFile.Open(GET_ASSET_PATH(_assetId)))
        {
            uint8 *buff = MEM::Ensure(inFile.GetSize(), _buff, _max);
            if (buff != nullptr && inFile.Read(buff, inFile.GetSize()))
            {
                retVal = _asset.Init(buff, inFile.GetSize(), buff + inFile.GetSize(), _max - inFile.GetSize());
                if (buff != _buff)
                {
                    MEM::Free(buff);
                }
            }
            inFile.Close();
        }
    }
    return retVal;
}

template bool LoadAsset<TextureAsset>(ASSET_ID _assetId, TextureAsset &_asset, uint8 *_buff, uSize _max);
//template bool LoadAsset<ShaderAsset>(ASSET_ID _assetId, AssetType &_asset, uint8 *_buff, uSize _max);
//template bool LoadAsset<MeshAsset>(ASSET_ID _assetId, AssetType &_asset, uint8 *_buff, uSize _max);
