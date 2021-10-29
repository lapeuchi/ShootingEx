#pragma once

extern void Init();
extern void Term();
extern void Update(float deltaTime);
extern void Render();
extern void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

class Asset
{
private:
	map<string, Texture*> _textures;

public:
	Asset();
	~Asset();

	void AddTexture(string key, Texture* value);
	Texture* GetTexture(string key);
};

class Camera
{
private:
	Sprite _sprite;

public:
	void SetPos(D3DXVECTOR2 pos);
	D3DXVECTOR2 GetPos();
};

extern Asset* _g_Asset;
extern Camera* _g_Camera;
extern Scene* _g_Scene;
extern Loading* _g_Loading;