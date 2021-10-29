#pragma once

class EndingScene : public Scene
{
public:
	EndingScene(bool isVictory);

	virtual ~EndingScene();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	Sprite _sprite;

	bool _isVictory;
};