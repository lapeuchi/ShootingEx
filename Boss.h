#pragma once

class Boss
{
public:
	Sprite _sprite;
	RECT _rect;

	Sprite _playerSprite;

	float _speed;
	float _walkSpeed;
	float _damage;
	float _health;
	bool _isDestroy;
	float _coolTime;
	float _coolTimer;
	bool _ableAttack;
	// Skill
	int _skillType;
	bool _isSkillEnd;
	int cnt;

	Boss(D3DXVECTOR2 pos, Sprite player);
	~Boss();

	void Update(float deltaTime);
	void Render();
	void GetDamage(float damage);
};