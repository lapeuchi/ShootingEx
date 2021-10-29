#pragma once

class Enemy
{
public:
	
	list<EnemyBullet*>* _enemyBullets;

	Enemy(int type, D3DXVECTOR2 pos, D3DXVECTOR2 dir, list<EnemyBullet*>* enemyBullets);
	~Enemy();

	Sprite _sprite;
	RECT _rect;

	D3DXVECTOR2 _dir;

	bool _isDestroy;
	float _health;
	float _damage;
	float _speed;
	float _attackTime;
	float _attackTimer;
	int _type;
	bool _isSky;
	bool _isinGame;

	void Update(float deltaTime);
	void Render();
	void GetDamage(float damage);
	float CarDistance(Sprite sprite1, Sprite sprite2);
};