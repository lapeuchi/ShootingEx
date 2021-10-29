#include "Header.h"

Asset* _g_Asset;
Camera* _g_Camera;
Scene* _g_Scene;
Loading* _g_Loading;

void LoadScene(Scene* scene)
{
	delete _g_Scene;
	_g_Scene = scene;
}

void Init()
{
	_g_Asset = new Asset();
	_g_Camera = new Camera();
	_g_Scene = new IntroScene();
	_g_Loading = new Loading();

	_g_Asset->AddTexture("Loading", new Texture(L"Img/Scene/Black", L"png", 0, 1));
	_g_Asset->AddTexture("Title_0", new Texture(L"Img/Scene/Title", L"jpg", 0, 1));
	_g_Asset->AddTexture("Title_1", new Texture(L"Img/Scene/Title", L"jpg", 1, 1));
	_g_Asset->AddTexture("Lose", new Texture(L"Img/Scene/Failed", L"jpg", 0, 1));
	_g_Asset->AddTexture("Victory", new Texture(L"Img/Scene/Victory", L"jpg", 0, 1));

	//Player
	_g_Asset->AddTexture("Player_Idle", new Texture(L"Img/Player/char", L"png", 0, 8));
	_g_Asset->AddTexture("Player_Left", new Texture(L"Img/Player/char", L"png", 1, 8));
	_g_Asset->AddTexture("Player_Right", new Texture(L"Img/Player/char", L"png", 2, 8));
	_g_Asset->AddTexture("Player_Bullet", new Texture(L"Img/Bullet/Bullet", L"png", 0, 1));
	_g_Asset->AddTexture("Player_Hampo", new Texture(L"Img/Bullet/Bullet", L"png", 2, 1));
	_g_Asset->AddTexture("Player_Arra", new Texture(L"Img/Bullet/Bullet", L"png", 3, 1));
	
	//Map
	_g_Asset->AddTexture("Map_1", new Texture(L"Img/Map/Map", L"png", 0, 1));
	_g_Asset->AddTexture("Map_2", new Texture(L"Img/Map/Map", L"png", 1, 1));
	_g_Asset->AddTexture("UI", new Texture(L"Img/Scene/UI", L"png", 0, 1));
	_g_Asset->AddTexture("Num", new Texture(L"Img/Num/Num", L"png", 0, 10));

	//Enemy
	_g_Asset->AddTexture("Enemy_A", new Texture(L"Img/Enemy/enemy", L"png", 1, 8));
	_g_Asset->AddTexture("Enemy_B", new Texture(L"Img/Enemy/enemy", L"png", 2, 8));
	_g_Asset->AddTexture("Enemy_Bullet", new Texture(L"Img/Bullet/Bullet", L"png", 1, 1));
	_g_Asset->AddTexture("Enemy_Boss", new Texture(L"Img/Enemy/enemy", L"png", 5, 13));
	_g_Asset->AddTexture("Trap", new Texture(L"Img/Bullet/trap", L"png", 0, 1)); 

	_g_Asset->AddTexture("Effect", new Texture(L"Img/Effect/exb", L"png", 0, 17));

	//bullet, misile, autoMisile, booster, fixBox, EventBox
	_g_Asset->AddTexture("Item_Bullet", new Texture(L"Img/Item/add", L"png", 0, 19));
	_g_Asset->AddTexture("Item_AutoMisile", new Texture(L"Img/Item/mis", L"png", 0, 18));
	_g_Asset->AddTexture("Item_Misile", new Texture(L"Img/Item/shi", L"png", 0, 17));
	_g_Asset->AddTexture("Item_Booster", new Texture(L"Img/Item/Item", L"png", 0, 18));
	_g_Asset->AddTexture("Item_FixBox", new Texture(L"Img/Item/fix", L"png", 0, 10));
	_g_Asset->AddTexture("Item_EventBox", new Texture(L"Img/Item/power", L"png", 0, 25));
}

void Term()
{
	delete _g_Scene;
	delete _g_Asset;
}

void Update(float deltaTime)
{
	if (_g_Scene != NULL)
		_g_Scene->Update(deltaTime);

	_g_Loading->Update(deltaTime);
}

void Render()
{
	if (_g_Scene != NULL)
		_g_Scene->Render();

	_g_Loading->Render();
}

void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (_g_Scene != NULL)
		_g_Scene->MsgProc(uMsg, wParam, lParam);
}

Asset::Asset()
{
	_textures.clear();
}

Asset::~Asset()
{
	for (auto it = _textures.begin(); it != _textures.end(); ++it)
	{
		if (it->second != NULL)
			delete it->second;
	}
}

void Asset::AddTexture(string key, Texture* value)
{
	if (_textures.find(key) == _textures.end())
	{
		_textures[key] = value;
	}
}

Texture* Asset::GetTexture(string key)
{
	if (_textures.find(key) == _textures.end())
	{
		return NULL;
	}
	return _textures[key];
}

void Camera::SetPos(D3DXVECTOR2 pos)
{
	_sprite._position = pos;
}

D3DXVECTOR2 Camera::GetPos()
{
	return _sprite._position;
}
