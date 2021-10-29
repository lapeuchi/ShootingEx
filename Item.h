#pragma once

class Item
{
public:
	int _type; //{bullet, misile, autoMisile, booster, fixBox, EventBox};

	Sprite _sprite;
	RECT _rect;

	float _speed;
	bool _isDestroy;
	Item(D3DXVECTOR2 pos, int type);
	~Item();

	void Update(float deltaTime);
	void Render();
};