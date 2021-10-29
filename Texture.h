#pragma once

class Texture
{
public:
	vector <LPDIRECT3DTEXTURE9> _textures;
	D3DXIMAGE_INFO _info;
	
	Texture(LPCWSTR filename, LPCWSTR extname, int state, int scene);
	~Texture();
	
	LPDIRECT3DTEXTURE9 GetTexture(int i)
	{
		return _textures[i];
	}

	int GetSize()
	{
		return _textures.size();
	}

	UINT GetWidth()
	{
		return _info.Width;
	}

	UINT GetHeight()
	{
		return _info.Height;
	}
};