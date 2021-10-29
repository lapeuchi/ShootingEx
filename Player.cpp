#include "Header.h"

Player::Player(list<Bullet*>* bullets, list<Hampo*>* hampos, list<Arra*>* arras)
{
	_sprite = Sprite();
	_sprite._position = D3DXVECTOR2(512, 600);
	_sprite._center = D3DXVECTOR2(64, 64);
	_sprite._scaleCen = D3DXVECTOR2(64, 64);
	_sprite._rotateCen = D3DXVECTOR2(64, 64);

	_bullets = bullets;
	_hampos = hampos;
	_arras = arras;
	SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);
	
	_speed = 300;
	_life = 3;
	_health = 100;
	_ableControl = false;
	_ableHit = true;
	_hitTimer = 0.0f;
	_hitTime = 3.0f;
	_isDestroy = false;
	_state = 0;

	_bulletDamage = 50;
	_bulletLevel = 0;
	_isBullet = false;
	_ableBulletCount = true;
	_curBulletAmmo = 30;
	_bulletAmmo = 30;
	_bulletReloadTime = 5.0f;
	_bulletReloadTimer = 0.0f;
	_bulletTime = 0.4f;
	_bulletTimer = 0;

	_isHampo = false;
	_hampoTime = 0.5f;
	_hampoTimer = 0.0f;
	_hampoDamage = 100.0f;
	_hampoReloadTime = 1.0f;
	_hampoReloadTimer = 0.0f;
	_curHampoAmmo = 5;
	_hampoAmmo = 5;

	_isArra = false;
	_arraTime = 2.0f;
	_arraTimer = 0.0f;
	_arraDamage = 100.0f;
	_curArraAmmo = 3;
	
	_isFocus = false;
	_focusTime = 5.0f;
	_focusTimer = 0.0f;

	_isAsist = false;
	_asistTime = 3.0f;
	_asistTimer = 0.0f;
	_curAssistAmmo = 3;
}

Player::~Player()
{

}

void Player::ChangeState(int state)
{
	if (_state != state)
	{
		if (state == 0)
		{
			_sprite.SetAnimation(true, 8, 0.05);
		}
		if (state == 1)
		{
			_sprite.SetAnimation(false, 8, 0.03);
		
		}
		if (state == 2)
		{
			_sprite.SetAnimation(false, 8, 0.03);
		}	
		_state = state;
	}
}



void Player::GetDamage(float damage)
{
	if (_ableHit)
	{
		_ableHit = false;
		_health -= damage;
	}

	if (_health <= 0)
	{
		--_life;
		_health = 100;
		if (_life <= 0)
		{
			_isDestroy = true;
		}
	}
}

void Player::Update(float deltaTime)
{
	_bulletTimer += deltaTime;
	_hampoTimer += deltaTime;
	_arraTimer += deltaTime;
	_focusTimer += deltaTime;
	_asistTimer += deltaTime;

	if(_curBulletAmmo < _bulletAmmo)
		_bulletReloadTimer += deltaTime;
	if (_bulletReloadTimer >= _bulletReloadTime)
	{
		_curBulletAmmo = 30;
		_bulletReloadTimer = 0.0f;
		printf("기관총 장전 %d\n", _curBulletAmmo);
		if (_isFocus == false)
		{
			printf("공속 %f\n", _bulletTime);
		}		
	}

	if (_curHampoAmmo < _hampoAmmo)
		_hampoReloadTimer += deltaTime;
	if (_hampoReloadTimer >= _hampoReloadTime)
	{
		++_curHampoAmmo;
		_hampoReloadTimer = 0.0f;
		printf("함포 장전 % d\n", _curHampoAmmo);
	}

	if (!_ableHit)
	{
		_hitTimer += deltaTime;
		if(_sprite._a>=255.0f)
			_sprite._a -= 700.0f * deltaTime;
		if(_sprite._a <= 50.0f)
			_sprite._a += 700.0f * deltaTime;
	}
	if (_hitTimer >= _hitTime)
	{
		_hitTimer = 0.0f;
		_ableHit = true;
		_sprite._a = 255.0f;
	}

	SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);
	//controll
	if (GetAsyncKeyState(VK_UP) && _sprite._position.y >= 0)
	{
		_sprite._position.y += -1 * _speed * deltaTime;
	}
	else if (GetAsyncKeyState(VK_DOWN) && _sprite._position.y <= 768)
	{
		_sprite._position.y += 1 * _speed * deltaTime;
	}
	if (GetAsyncKeyState(VK_LEFT) && _sprite._position.x >= 0)
	{
		ChangeState(1);
		_sprite._position.x += -1 * _speed * deltaTime;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && _sprite._position.x <= 1024)
	{
		ChangeState(2);
		_sprite._position.x += 1 * _speed * deltaTime;
	}
	else
	{
		ChangeState(0);
	}

	if (GetAsyncKeyState(VK_LCONTROL))		//기관총
	{
		if (_bulletTimer >= _bulletTime && _curBulletAmmo > 0)
		{
			_bulletTimer = 0.0f;
			if (_isFocus == false)
			{
				--_curBulletAmmo;
			}
			
			_isBullet = true;
			
			printf("기관총 총알 : %d\n", _curBulletAmmo);
		}
		else
			_isBullet = false;
	}

	if (GetAsyncKeyState(0X41))		//함포 : Akey
	{
		if (_hampoTimer >= _hampoTime && _curHampoAmmo > 0)
		{
			_isHampo = true;
			--_curHampoAmmo;
			_hampoTimer = 0.0f;
			printf("함포 : % d\n", _curHampoAmmo);
		}
		else
			_isHampo = false;
	}
	
	if (GetAsyncKeyState(0X53))		//어뢰 : Skey
	{
		if (_arraTimer >= _arraTime && _curArraAmmo > 0)
		{
			_isArra = true;
			_arraTimer = 0.0f;
			--_curArraAmmo;
		}	
		else
			_isArra = false;
	}
	

	if (GetAsyncKeyState(0X44))		//미사일 : Dkey
 	{
		_isMisile = true;
	}

	if (GetAsyncKeyState(0X46))	// 집중 사격 (스킬)
	{
		if(_focusTimer >= _focusTime && _isFocus == false)
		{ 
			_isFocus = true;
			_focusTimer = 0.0f;
			
		}
	}
	if (_focusTimer >= 5.0f && _isFocus == true)
	{
		_focusTimer = 0.0f;
		_isFocus = false;
	}

	if (GetAsyncKeyState(VK_F4))	// 공중 지원 (스킬)
	{
		if (_asistTimer >= _asistTime && _curAssistAmmo > 0)
		{
			_isAsist = true;
			_asistTimer = 0.0f;
			--_curAssistAmmo;
		}
		else
		{
			_isAsist = false;
		}
	}

	
	//controll end
	_sprite.Update(deltaTime);
}

void Player::Render()
{
	if (_state == 1)
	{
		_sprite.Render(_g_Asset->GetTexture("Player_Left"));	
	}
	if (_state == 2)
	{	
		_sprite.Render(_g_Asset->GetTexture("Player_Right"));
	}
	if (_state == 0)
	{	
		_sprite.Render(_g_Asset->GetTexture("Player_Idle"));
	}
}