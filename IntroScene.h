#pragma once

class IntroScene : public Scene
{
public:
	IntroScene();
	virtual ~IntroScene();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	Sprite _sprite;

	int _maxButton;
	int _curButton;
	float _selectTimer;
	float _selectTime;
};