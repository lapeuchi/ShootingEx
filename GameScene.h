#pragma once

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	Map* _map;
	Player* _player;
	Boss* _boss;
	UI* _UI;
	list<Enemy*> _enemys;
	list<Bullet*> _bullets;
	list<EnemyBullet*> _enemyBullets;
	list<Effect*> _effects;
	list<Hampo*> _hampos;
	list<Arra*> _arras;
	list<Item*> _items;
	list<Trap*> _traps;

	Num* _num[9];

	float _startTime;
	int _turn;
	RECT _rect;

	int _score;
	int _bullet;
	int _hampo;
	int _misile;
	list<float> tmp;
	bool existEnemy;
};