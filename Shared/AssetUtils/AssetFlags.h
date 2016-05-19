#pragma once

enum AssetFlags
{
    ASSET_OWNMEM     = 0x40000000,
    ASSET_VALID      = 0x80000000,
    ASSET_TEXTURE    = 0x01000000,
    ASSET_SHADER     = 0x02000000,
    ASSET_MESH       = 0x04000000
};

enum TextureFlags
{
    TEXTURE_BGR24   = 0x00000001,
    TEXTURE_BGRA32  = 0x00000002
};

enum ShaderFlags
{
};

enum MeshFlags
{
};
