#include "Header.h"

Enemy::Enemy(int type, D3DXVECTOR2 pos, D3DXVECTOR2 dir, list<EnemyBullet*>* enemyBullets)
{
	_sprite = Sprite();

	_sprite._position = pos;
	_isDestroy = false;
	_dir = dir;
	D3DXVec2Normalize(&_dir, &dir);
	_type = type;
	_enemyBullets = enemyBullets;
	_isinGame = false;

	if (_type == 1)	//바다 적 
	{
		_sprite._center = D3DXVECTOR2(128, 128);
		_sprite._rotateCen = D3DXVECTOR2(128, 128);
		_sprite._scaleCen = D3DXVECTOR2(128, 128);
		_sprite._rotate = 180;
		_speed = 200.f;
		_health = 100;
		_damage = 50;
		_attackTime = 1.5f;
		_isSky = false;
		_sprite.SetAnimation(true, 8, 0.1);
	}

	if (_type == 2) //공중 적
	{
		_sprite._center = D3DXVECTOR2(64, 64);
		_sprite._rotateCen = D3DXVECTOR2(64, 64);
		_sprite._scaleCen = D3DXVECTOR2(64, 64);
		_speed = 400.f;
		_health = 100;
		_damage = 50;
		_attackTime = 1.f;
		_isSky = true;
		_sprite.SetAnimation(true, 8, 0.1);
	}

	_attackTimer = 0;
}

Enemy::~Enemy() {}

void Enemy::Update(float deltaTime)
{
	
	_attackTimer += deltaTime;

	if (_sprite._position.x >= 0 && _sprite._position.x <= 1024 && _sprite._position.y >= 0 && _sprite._position.y <= 768)
	{
		_isinGame = true;
	}
	else _isinGame = false;

	if (_type == 1)
	{
		_sprite._position += _dir * _speed * deltaTime;
		SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);
	}

	if (_type == 2)
	{
		_sprite._position += _dir * _speed * deltaTime;
		SetRect(&_rect, _sprite._position.x - 5, _sprite._position.y - 5, _sprite._position.x + 5, _sprite._position.y + 5);
	}

	if (_sprite._position.y >= 868)
	{
		_isDestroy = true;
	}

	_sprite.Update(deltaTime);
}

void Enemy::Render()
{
	if (_type == 1)
	{
		_sprite.Render(_g_Asset->GetTexture("Enemy_A"));
	}
	else if (_type == 2)
	{
		_sprite.Render(_g_Asset->GetTexture("Enemy_B"));
	}
}

void Enemy::GetDamage(float damage)
{
	_health -= damage;
	if (_health <= 0)
	{
		_isDestroy = true;
	}
}

float Enemy::CarDistance(Sprite sprite1, Sprite sprite2)
{
	return sqrt
	(
		(
			(sprite1._position.x - sprite2._position.x) * (sprite1._position.x - sprite2._position.x)
		) 
			+
		(
			 (sprite1._position.y - sprite2._position.y) * (sprite1._position.y - sprite2._position.y)
		)
	);
}