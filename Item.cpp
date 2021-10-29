#include "Header.h"
//{bullet, misile, autoMisile, booster, fixBox, EventBox};

Item::Item(D3DXVECTOR2 pos, int type)
{
	_sprite = Sprite();
	RECT _rect;
	_sprite._position = pos;
	_sprite._scaleCen = D3DXVECTOR2(32, 32);
	_sprite._rotateCen = D3DXVECTOR2(32, 32);
	_sprite._center = D3DXVECTOR2(32, 32);
	_speed = 100.f;
	_isDestroy = false;
	//±â°üÃÑ Åº¾Ë
	_type = type;

	if (_type == 0)
	{
		_sprite.SetAnimation(true, 19, 0.5f);
	}
	if (_type == 1)
	{
		_sprite.SetAnimation(true, 17, 0.5f);
	}
	if (_type == 2)
	{
		_sprite.SetAnimation(true, 18, 0.5f);
	}
	if (_type == 3)
	{
		_sprite.SetAnimation(true, 18, 0.5f);
	}
}

Item::~Item()
{

}

void Item::Update(float deltaTime)
{
	_sprite._position.y += _speed * deltaTime;

	SetRect(&_rect, _sprite._position.x - 16, _sprite._position.y - 16, _sprite._position.x + 16, _sprite._position.y + 16);
	
	_sprite.Update(deltaTime);
}

void Item::Render()
{

	if (_type == 0)
	{
		_sprite.Render(_g_Asset->GetTexture("Item_Bullet"));
	}

	if (_type == 1)
	{
		_sprite.Render(_g_Asset->GetTexture("Item_Misile"));
	}
	
	if (_type == 2)
	{
		_sprite.Render(_g_Asset->GetTexture("Item_AutoMisile"));
	}

	if (_type == 3)
	{
		_sprite.Render(_g_Asset->GetTexture("Item_Booster"));
	}
	
}
