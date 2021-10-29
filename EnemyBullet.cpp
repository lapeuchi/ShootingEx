#include "Header.h"

EnemyBullet::EnemyBullet(D3DXVECTOR2 pos, D3DXVECTOR2 dir, float speed, float damage)
{
	_sprite = Sprite();

	_speed = speed;
	_damage = damage;

	_sprite._position = pos;
	_sprite._center = D3DXVECTOR2(16, 16);
	_sprite._rotateCen = D3DXVECTOR2(16, 16);
	_sprite._scaleCen = D3DXVECTOR2(16, 16);

	_isDestroy = false;

	D3DXVec2Normalize(&_dir, &dir);

	_sprite.SetAnimation(true, 1, 0);
}

EnemyBullet::~EnemyBullet() {}

void EnemyBullet::Update(float deltaTime)
{
	_sprite._position += _dir * _speed * deltaTime;

	if (_sprite._position.y >= 868) {
		_isDestroy = true;
	}

	SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);
	
	_sprite.Update(deltaTime);
}

void EnemyBullet::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Enemy_Bullet"));
}