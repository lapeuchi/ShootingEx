#include "Header.h"

UI::UI()
{
	_sprite = Sprite();
	_sprite._position = D3DXVECTOR2(512, 384);
	_sprite._center = D3DXVECTOR2(512, 384);
	_sprite._rotateCen = D3DXVECTOR2(512, 384);
	_sprite._scaleCen = D3DXVECTOR2(512, 384);
}

UI::~UI()
{

}

void UI::Update(float deltaTime)
{
	_sprite.Update(deltaTime);
}

void UI::Render()
{
	_sprite.Render(_g_Asset->GetTexture("UI"));
}