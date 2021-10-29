#include "Header.h"

Trap::Trap(D3DXVECTOR2 pos, int type)
{
	_sprite = Sprite();
	_sprite._center = D3DXVECTOR2(384, 384);
	_speed = 100;
	_isDestroy = false;
	_type = 0;
}

Trap::~Trap() {}

void Trap::Update(float deltaTime)
{
	SetRect(&_rect, _sprite._position.x - 5, _sprite._position.y - 5, _sprite._position.x + 5, _sprite._position.y + 5);
	
	_sprite._position.y += deltaTime * _speed * -1;

	if (_sprite._position.y >= 100)
	{
		_isDestroy = true;
	}

	_sprite.Update(deltaTime);
}

void Trap::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Trap"));
}