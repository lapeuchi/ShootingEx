#pragma once

class Player
{
public:
	Sprite _sprite;
	RECT _rect;
	list<Bullet*> *_bullets;
	list<Hampo*>* _hampos;
	list<Arra*>* _arras;

	float _speed;
	float _life;
	float _health;
	
	bool _ableControl;
	bool _isDestroy;
	bool _ableHit;
	float _hitTimer;
	float _hitTime;
	
	bool _isBullet;
	float _bulletTime;
	float _bulletTimer;
	float _bulletDamage;
	int _bulletLevel;
	bool _ableBulletCount;
	int _curBulletAmmo;
	int _bulletAmmo;
	float _bulletReloadTime;
	float _bulletReloadTimer;

	bool _isHampo;
	float _hampoTime;
	float _hampoTimer;
	float _hampoDamage;
	float _hampoReloadTime;
	float _hampoReloadTimer;
	int _curHampoAmmo;
	int _hampoAmmo;

	bool _isArra;
	float _arraTime;
	float _arraTimer;
	float _arraDamage;
	int _curArraAmmo;
	int _ArraAmmo;

	bool _isMisile;
	float _misileTime;
	float _misileTimer;
	float _misileDamage;
	int _curMisileAmmo;
	int _MisileAmmo;

	bool _isFocus;
	float _focusTime;
	float _focusTimer;

	bool _isAsist;
	float _asistTime;
	float _asistTimer;
	int _curAssistAmmo;
	int _assistAmmo;

	int _state;

	Player(list<Bullet*>* bullets, list<Hampo*>* hampos, list<Arra*>* arras);
	~Player();
	void ChangeState(int state);
	void GetDamage(float damage);

	void Update(float deltaTime);
	void Render();
};
