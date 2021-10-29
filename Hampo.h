#pragma once

class Hampo
{
public:
	Sprite _sprite;
	RECT _rect;

	float _speed;
	float _damage;
	D3DXVECTOR2 _dir;
	bool _isDestroy;
	bool _isRand;
	float randX;
	float randY;
	float x;
	float y;
	Hampo(D3DXVECTOR2 pos, D3DXVECTOR2 dir, float speed, float damage);
	~Hampo();

	void Update(float deltaTime);
	void Render();

};