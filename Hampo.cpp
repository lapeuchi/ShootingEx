#include "Header.h"

Hampo::Hampo(D3DXVECTOR2 pos, D3DXVECTOR2 dir, float speed, float damage)
{
	_sprite = Sprite();
	_sprite._position = pos;
	_sprite._scaleCen = D3DXVECTOR2(16, 16);
	_sprite._rotateCen = D3DXVECTOR2(16, 16);
	_sprite._center = D3DXVECTOR2(16, 16);
	
	_speed = speed;
	_damage = damage;
	_isDestroy = false;
	_isRand = false;
	x = rand() % 8;
	y = rand() % 8;

	if (x == 0) randX = 0; if (x == 1) randX = 0.25f; if (x == 2) randX = 0.5f;
	if (x == 3) randX == 0.75; if (x == 4) randX = 1;
	if (y == 0) randY = 0; if (y == 1) randY = 0.25f; if (y == 2) randY = 0.5f;
	if (y == 3) randY == 0.75; if (y == 4) randY = 1;
	D3DXVec2Normalize(&_dir, &dir);

	_sprite.SetAnimation(true, 1, 0.0f);
}

Hampo::~Hampo()
{

}


void Hampo::Update(float deltaTime)
{
	SetRect(&_rect, _sprite._position.x - 8, _sprite._position.y - 8, _sprite._position.x + 8, _sprite._position.y + 8);
	
	_sprite._position += _dir * _speed * deltaTime;

	if (_sprite._position.y <= -100) {
		_isDestroy = true;
	}

	_sprite.Update(deltaTime);
}

void Hampo::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Player_Hampo"));
}