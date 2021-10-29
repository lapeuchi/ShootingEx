#include "Header.h"

Boss::Boss(D3DXVECTOR2 pos, Sprite player)
{
	_sprite = Sprite();
	_playerSprite = player;
	_sprite._center = D3DXVECTOR2(64, 64);
	_sprite._rotateCen = D3DXVECTOR2(64, 64);
	_sprite._scaleCen = D3DXVECTOR2(64, 64);
	_sprite._scale = D3DXVECTOR2(2, 2);
	_sprite._position = pos;

	_speed = 1000.0f;
	_walkSpeed = 95.0f;
	_health = 6000.0f;
	_damage = 20.0f;
	_coolTime = 5.0f;
	_coolTimer = 0.0f;

	_isDestroy = false;
	_ableAttack = false;
	_skillType = -1;
	_isSkillEnd = true;
	_sprite.SetAnimation(true, 13, 0.1f);
	cnt = 0;
}

Boss::~Boss()
{

}

void Boss::Update(float deltaTime)
{
	if(_ableAttack==true)
		_coolTimer += deltaTime;

	if (_coolTimer >= _coolTime && _isSkillEnd)
	{
		_skillType = rand() % 1;
		_coolTimer = 0;
	}

	if (_skillType == 0)
	{
		_isSkillEnd = false;
		cnt = 0;
		if (cnt == 0)
		{
			_sprite._position.y += _speed * deltaTime;
			if (_sprite._position.y >= 850)
				cnt = 1;
			printf("Lev:1)%d\n", cnt);
		}
		if (cnt == 1)
		{
			_sprite._position.y -= _speed * deltaTime;
			if (_sprite._position.y <= 100)
				cnt = 2;
			printf("Lev:2)%d\n", cnt);
		}
		if (cnt == 2)
		{
			_isSkillEnd = true;
		}
		
	}
	else
	{

	}

	SetRect(&_rect, _sprite._position.x - 32, _sprite._position.y - 32, _sprite._position.x + 32, _sprite._position.y + 32);
	_sprite.Update(deltaTime);
}

void Boss::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Enemy_Boss"));
}

void Boss::GetDamage(float damage)
{
	_health -= damage;
	if (_health <= 0)
	{
		_isDestroy = true;
		
	}
}