#pragma once

class Trap
{
public:
	Sprite _sprite;

	Trap(D3DXVECTOR2 pos, int type);
	~Trap();
	float _speed;
	bool _isDestroy;
	int _type;
	RECT _rect;

	void Update(float deltaTime);
	void Render();
};