#pragma once

class UI
{
public:
	Sprite _sprite;

	UI();
	~UI();

	void Update(float deltaTime);
	void Render();

};