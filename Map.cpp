#include "Header.h"

Map::Map()
{
	_sprite = Sprite();
	_speed = 100.0f;

	_sprite._position = D3DXVECTOR2(512, -2200);
	_sprite._center = D3DXVECTOR2(512, 3072);
	_sprite._rotateCen = D3DXVECTOR2(512, 3072);
	_sprite._scaleCen = D3DXVECTOR2(512, 3072);
}

void Map::Update(float deltaTime)
{
	_sprite._position.y += 1 * _speed * deltaTime;
	_sprite.Update(deltaTime);
}

void Map::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Map_1"));
}
