#pragma once

class Arra
{
public:
	Arra(D3DXVECTOR2 pos, Sprite target, float speed, float damage);
	~Arra();

	Sprite _sprite;

	D3DXVECTOR2 _dir;

	float _speed;
	float _damage;
	bool _isDestroy;

	RECT _rect;
	
	float _distance;

	void Update(float deltaTime);
	void Render();
};