#include "Header.h"

EndingScene::EndingScene(bool isVictory)
{
	_sprite = Sprite();
	_sprite._position = D3DXVECTOR2(0, 0);

	_isVictory = isVictory;
}

EndingScene::~EndingScene()
{

}

void EndingScene::Update(float deltaTime)
{
	_sprite.Update(deltaTime);

	if (GetAsyncKeyState(VK_RETURN))
	{
		_g_Loading->LoadScene(new IntroScene());
	}
}

void EndingScene::Render()
{
	if (_isVictory)
		_sprite.Render(_g_Asset->GetTexture("Victory"));
	else
		_sprite.Render(_g_Asset->GetTexture("Lose"));
}

void EndingScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}