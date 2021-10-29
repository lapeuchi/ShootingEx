#include "Header.h"

Effect::Effect(D3DXVECTOR2 pos)
{
	_sprite = Sprite();
	_sprite._position = pos;
	_sprite._center = D3DXVECTOR2(128, 128);
	_sprite._rotateCen = D3DXVECTOR2(128, 128);
	_sprite._scaleCen = D3DXVECTOR2(128, 128);
	_sprite._scale = D3DXVECTOR2(2, 2);

	_isDestroy = false;
	_sprite.SetAnimation(false, 17, 0.0f);
}

Effect::~Effect()
{
	
}

void Effect::Update(float deltaTime)
{	
	if (_sprite._isAniEnd)
	{
		_isDestroy = true;
	}
	
	_sprite.Update(deltaTime);
}

void Effect::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Effect"));
}