#pragma once

class EnemyBullet
{
public:
	EnemyBullet(D3DXVECTOR2 pos, D3DXVECTOR2 dir, float speed, float damage);
	~EnemyBullet();

	Sprite _sprite;
	RECT _rect;

	D3DXVECTOR2 _dir;
	float _speed;
	float _damage;
	bool _isDestroy;

	void Update(float deltaTime);
	void Render();
};