#include "Header.h"

IntroScene::IntroScene()
{
	_sprite = Sprite();
	_sprite._position = D3DXVECTOR2(0, 0);
	_curButton = 0;
	_maxButton = 1;
	_selectTime = 0.3f;
	_selectTimer = 0.0f;
}

IntroScene::~IntroScene()
{

}

void IntroScene::Update(float deltaTime)
{
	_selectTimer += deltaTime;
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (_curButton == 0)
		{
			_g_Loading->LoadScene(new GameScene());
		}
		if (_curButton == 1)
		{
			PostQuitMessage(0);
		}
	}

	if (GetAsyncKeyState(VK_UP) && _selectTimer >= _selectTime)
	{
		if (_curButton > 0)
			--_curButton;
		else
			_curButton = _maxButton;
		_selectTimer = 0.0f;
	}
	if (GetAsyncKeyState(VK_DOWN) && _selectTimer >= _selectTime)
	{
		if (_curButton < _maxButton)
			++_curButton;
		else
			_curButton = 0;
		_selectTimer = 0.0f;
	}

	_sprite.Update(deltaTime);
}

void IntroScene::Render()
{
	if (_curButton == 0)
	{
		_sprite.Render(_g_Asset->GetTexture("Title_0"));
	}
	else if (_curButton == 1)
	{
		_sprite.Render(_g_Asset->GetTexture("Title_1"));
	}
}

void IntroScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}