#pragma once

class Bullet
{
public:
	Bullet(D3DXVECTOR2 pos, D3DXVECTOR2 dir, float speed, float damage);
	~Bullet();

	Sprite _sprite;
	
	D3DXVECTOR2 _dir;

	float _speed;
	float _damage;
	bool _isDestroy;

	RECT _rect;

	void Update(float deltaTime);
	void Render();
};