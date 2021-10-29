#include "Header.h"

Bullet::Bullet(D3DXVECTOR2 pos, D3DXVECTOR2 dir, float speed, float damage)
{
	_sprite = Sprite();
	_speed = speed;
	_damage = damage;
	D3DXVec2Normalize(&_dir, &dir);

	_sprite._position = pos;
	_sprite._center = D3DXVECTOR2(16, 16);
	_sprite._rotateCen = D3DXVECTOR2(16, 16);
	_sprite._scaleCen = D3DXVECTOR2(16, 16);

	_sprite.SetAnimation(true, 1, 0);

	_isDestroy = false;
}

Bullet::~Bullet()
{

}

void Bullet::Update(float deltaTime)
{
	SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);

	_sprite._position += _dir * _speed * deltaTime;
		
	if (_sprite._position.y <= -100)
	{
		_isDestroy = true;
		
	}

	_sprite.Update(deltaTime);
}

void Bullet::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Player_Bullet"));
}