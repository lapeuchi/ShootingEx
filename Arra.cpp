#include "Header.h"

Arra::Arra(D3DXVECTOR2 pos, Sprite target, float speed, float damage)
{
	_sprite = Sprite();
	_sprite._center = D3DXVECTOR2(64, 64);
	_sprite._rotateCen = D3DXVECTOR2(64, 64);
	_sprite._scaleCen = D3DXVECTOR2(64, 64);

	_sprite._position = pos;
	_speed = speed;
	_damage = damage;

	_isDestroy = false;

	_distance = 0.0f;
	D3DXVec2Normalize(&_dir, new D3DXVECTOR2(target._position.x, target._position.y));
}

Arra::~Arra()
{

}

void Arra::Update(float deltaTime)
{	
//	D3DXVec2Normalize(&_dir, &_dir);

	SetRect(&_rect, _sprite._position.x -= 10, _sprite._position.y -= 10, _sprite._position.x += 10, _sprite._position.y += 10);

	_sprite._position += _dir * _speed * deltaTime;
	if (_sprite._position.y <= 150)
		_isDestroy = true;
	_sprite.Update(deltaTime);
}

void Arra::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Player_Arra"));
}