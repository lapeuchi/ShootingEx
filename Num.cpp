#include "Header.h"

Num::Num(D3DXVECTOR2 pos) 
{
	_sprite = Sprite();
	_sprite._center = D3DXVECTOR2(17.5, 20);
	_sprite._position = pos;
}

Num::~Num()
{

}

void Num::Update(float deltaTime)
{
	_sprite.Update(deltaTime);
	if (_sprite._scene < 0)
	{
		_sprite._scene = 0;
	}

}

void Num::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Num"));
}