#include "Header.h"

GameScene::GameScene()
{
	_map = new Map();
	_player = new Player(&_bullets, &_hampos, &_arras);
	
	_boss = new Boss(D3DXVECTOR2(540, -3000), _player->_sprite);

	_UI = new UI();
	existEnemy = false;

	_bullets.clear();
	_hampos.clear();
	_arras.clear();
	_items.clear();
	_traps.clear();
	_enemys.clear();
	_enemyBullets.clear();
	_effects.clear();
	_startTime = 0.0f;
	_turn = 1;

	_score = 0;

	//점수
	_num[0] = new Num(D3DXVECTOR2(834, 230));
	_num[1] = new Num(D3DXVECTOR2(869, 230));
	_num[2] = new Num(D3DXVECTOR2(904, 230));
	_num[3] = new Num(D3DXVECTOR2(939, 230));
	_num[4] = new Num(D3DXVECTOR2(974, 230));
	//life
	_num[5] = new Num(D3DXVECTOR2(939, 435));
	//총알
	_num[6] = new Num(D3DXVECTOR2(919, 485));
	_num[7] = new Num(D3DXVECTOR2(949, 485));

	//assist
	_num[8] = new Num(D3DXVECTOR2(939, 635));

	tmp.clear();
} 

GameScene::~GameScene()
{

}

void GameScene::Update(float deltaTime)
{
	_startTime += deltaTime;

	//controll
	if (GetAsyncKeyState(VK_RETURN))
		_g_Loading->LoadScene(new GameScene);

	if (_player->_isBullet == true)
	{
		_player->_bullets->push_back(new Bullet(_player->_sprite._position, D3DXVECTOR2(0, -1), 1000.0f, _player->_bulletDamage));
		printf("[%.2f] Player->Attack!\n", _startTime);
		if (_player->_isFocus == true)
		{
			_player->_bulletTime = 0.1f;
			printf("공속강화중", _player->_bulletTime);
		}
		else _player->_bulletTime = 0.4f;
	}

	if (_player->_isHampo == true)
	{
		printf("hamo");
		_player->_hampos->push_back(new Hampo(_player->_sprite._position, D3DXVECTOR2(0, -1), 1000.0f, _player->_hampoDamage));
	}
	
	if (_player->_isArra == true)
	{
		_player->_arras->push_back(new Arra(_player->_sprite._position, _player->_sprite, 1000.0f, _player->_arraDamage));
	}

	if (_player->_isAsist == true)
	{
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
		_effects.push_back(new Effect(D3DXVECTOR2(rand() % 1024, rand() % 768)));
	}

	//controll end

	//GameEvent
	
	if (_startTime >= 2.0f && _turn == 1)
	{
		printf("[%.2f] Turn 1!\n", _startTime);
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(512, -500), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(1, D3DXVECTOR2(312, -200), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(812, -400), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(-200, 300), _player->_sprite._position, &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(1500, -500), _player->_sprite._position, &_enemyBullets));
		_traps.push_back(new Trap(D3DXVECTOR2(rand() % 1025, rand() % 313), 1));
		_traps.push_back(new Trap(D3DXVECTOR2(rand() % 3, rand() % 313), 1));
		_turn++;
	}

	if (_startTime >= 7.0f && _turn == 2)
	{
		_enemys.push_back(new Enemy(1, D3DXVECTOR2(212, -540), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(352, -520), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(1, D3DXVECTOR2(612, -560), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(-200, 200), _player->_sprite._position, &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(1500, 300), _player->_sprite._position, &_enemyBullets));
		printf("[%.2f] Turn 2!\n", _startTime);
		_turn++;
	}

	if (_startTime >= 14.0f && _turn == 3)
	{
		_enemys.push_back(new Enemy(1, D3DXVECTOR2(212, -540), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(352, -520), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(1, D3DXVECTOR2(612, -560), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(-200, 200), _player->_sprite._position, &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(1500, 300), _player->_sprite._position, &_enemyBullets));
		printf("[%.2f] Turn 2!\n", _startTime);
		_turn++;
	}

	if (_startTime >= 20.0f && _turn == 4)
	{
		_enemys.push_back(new Enemy(1, D3DXVECTOR2(212, -540), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(352, -520), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(1, D3DXVECTOR2(612, -560), D3DXVECTOR2(0, 1), &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(-200, 200), _player->_sprite._position, &_enemyBullets));
		_enemys.push_back(new Enemy(2, D3DXVECTOR2(1500, 300), _player->_sprite._position, &_enemyBullets));
		printf("[%.2f] Turn 2!\n", _startTime);
		_turn++;
	}
	if (_startTime <= 33.0f)
	{
		_boss->_sprite._position.y += deltaTime * _boss->_walkSpeed;
	}
	if (_startTime >= 33.0f && _turn == 5)
	{
		_map->_speed = 0;
		_boss->_ableAttack = true;
		++_turn;
	}	
		
	if (_startTime >= 40.0f && _turn == 6 && _boss->_isDestroy == true)
	{
		delete _boss;
		_g_Loading->LoadScene(new EndingScene(true));
	}
	
	if (_player->_isDestroy)
	{
		printf("[%.2f] Player->isDestroy!\n", _startTime);
		_g_Loading->LoadScene(new EndingScene(false));
		_player->_isDestroy = false;
	}

	_num[0]->_sprite._scene = int(_score / 10000);
	_num[1]->_sprite._scene = int(_score % 10000 / 1000);
	_num[2]->_sprite._scene = int(_score % 1000 / 100);
	_num[3]->_sprite._scene = int(_score % 100 / 10);

	_num[4]->_sprite._scene = _score % 10;
	_num[5]->_sprite._scene = _player->_life;
	
	
	_num[6]->_sprite._scene = _player->_curBulletAmmo /10;
	_num[7]->_sprite._scene = _player->_curBulletAmmo % 10;

	_num[8]->_sprite._scene = _player->_curAssistAmmo;
	// GameEvent end.

	for (auto it = _enemys.begin(); it != _enemys.end(); ++it)
	{
		if ((*it)->_attackTimer >= (*it)->_attackTime)
		{
			if ((*it)->_type == 1)
			{
				_enemyBullets.push_back(new EnemyBullet((*it)->_sprite._position, (*it)->_dir, (*it)->_speed + 200, (*it)->_damage));
			}
			else if ((*it)->_type == 2)
			{
				_enemyBullets.push_back(new EnemyBullet((*it)->_sprite._position, D3DXVECTOR2(0, 1), (*it)->_speed + 300, (*it)->_damage));
				_enemyBullets.push_back(new EnemyBullet((*it)->_sprite._position, D3DXVECTOR2(1, 0), (*it)->_speed + 300, (*it)->_damage));
				_enemyBullets.push_back(new EnemyBullet((*it)->_sprite._position, D3DXVECTOR2(-1, 0), (*it)->_speed + 300, (*it)->_damage));
				_enemyBullets.push_back(new EnemyBullet((*it)->_sprite._position, D3DXVECTOR2(0, -1), (*it)->_speed + 300, (*it)->_damage));
			}
			
			printf("pos(%f,%f) dir(%f) speed(%f) (damage)%f\n", (*it)->_sprite._position.x, (*it)->_sprite._position.y, (*it)->_dir, (*it)->_speed + 200.0f, (*it)->_damage);
			(*it)->_attackTimer = 0;
		}
	}

	//충돌 처리 & effect

	for (auto it = _bullets.begin(); it != _bullets.end(); ++it)
	{//bullets & enemyBullets
		for (auto itt = _enemyBullets.begin(); itt != _enemyBullets.end(); ++itt)
		{
			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect))
			{
				_effects.push_back(new Effect((*it)->_sprite._position));
				_effects.push_back(new Effect((*itt)->_sprite._position));
				(*it)->_isDestroy = true;
				(*itt)->_isDestroy = true;
			}
		}
	}

	for (auto it = _bullets.begin(); it != _bullets.end(); ++it)
	{ //bullets & enemys
		for (auto itt = _enemys.begin(); itt != _enemys.end(); ++itt)
		{
			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect))
			{
				_effects.push_back(new Effect((*it)->_sprite._position));
				_effects.push_back(new Effect((*itt)->_sprite._position));
				(*itt)->GetDamage((_player->_bulletDamage));
				(*it)->_isDestroy = true;
			}
		}
	}

	for (auto it = _hampos.begin(); it != _hampos.end(); ++it)
	{//hampos & enemys
		for (auto itt = _enemys.begin(); itt != _enemys.end(); ++itt)
		{
			if ((*itt)->_isinGame == true)
			{
				(*it)->_isRand = true;
			}
			else (*it)->_isRand = false;
			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect))
			{
				_effects.push_back(new Effect((*it)->_sprite._position));
				_effects.push_back(new Effect((*itt)->_sprite._position));
				(*itt)->GetDamage((_player->_hampoDamage));
				(*it)->_isDestroy = true;
			}
		}
	}

	for (auto it = _arras.begin(); it != _arras.end(); ++it)
	{
		//arras & enemys
		for (auto itt = _enemys.begin(); itt != _enemys.end(); ++itt)
		{
			 tmp.push_back((*itt)->CarDistance(_player->_sprite, (*itt)->_sprite));
			 printf("%.2f\n", (*it)->_distance);
			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect))
			{
				_effects.push_back(new Effect((*it)->_sprite._position));
				_effects.push_back(new Effect((*itt)->_sprite._position));
				(*itt)->GetDamage(_player->_arraDamage);
				(*it)->_isDestroy = true;
			}
		}
	}

	for (auto it = _enemyBullets.begin(); it != _enemyBullets.end(); ++it)
	{	//enemyBullets & player
		if (IntersectRect(&_rect, &(*it)->_rect, &_player->_rect))
		{
			_effects.push_back(new Effect((*it)->_sprite._position));
			_effects.push_back(new Effect(_player->_sprite._position));
			if (_player->_ableHit == false)
				printf("무적시간!");
			_player->GetDamage(((*it)->_damage));
			(*it)->_isDestroy = true;
		}
	}

	for (auto it = _enemys.begin(); it != _enemys.end(); ++it)
	{	//enemy & player
		if (IntersectRect(&_rect, &(*it)->_rect, &_player->_rect))
		{
			_effects.push_back(new Effect((*it)->_sprite._position));
			_effects.push_back(new Effect(_player->_sprite._position));
			_player->GetDamage(((*it)->_damage));
		}
	}

	for (auto it = _items.begin(); it != _items.end(); ++it)
	{
		if (IntersectRect(&_rect, &(*it)->_rect, &_player->_rect))
		{
			if ((*it)->_type == 0)
			{
				_player->_curBulletAmmo += 30;
				if (_player->_curBulletAmmo >= 180)
					_player->_curBulletAmmo = _player->_bulletAmmo;
				printf("%d", _player->_curBulletAmmo);
				++_player->_curAssistAmmo;
			}
			if ((*it)->_type == 1)
			{
				_player->_speed += 30;
			}
			if ((*it)->_type == 2)
			{
				_player->_health = 100;
			}
			if ((*it)->_type == 3)
			{
				_player->_speed += 30;
			}
			(*it)->_isDestroy = true;
		}
	}

	if (IntersectRect(&_rect, &_player->_rect, &_boss->_rect))
	{	// boss & player
		_player->GetDamage(_boss->_damage);
		_effects.push_back(new Effect(_boss->_sprite._position));
		_effects.push_back(new Effect(_player->_sprite._position));
	}

	for (auto it = _bullets.begin(); it != _bullets.end(); ++it)
	{ //bullet & boss
		if (IntersectRect(&_rect, &(*it)->_rect, &_boss->_rect))
		{
			(*it)->_isDestroy = true;
			_boss->GetDamage(_player->_bulletDamage);
			_effects.push_back(new Effect((*it)->_sprite._position));
		}
	}

	for (auto it = _traps.begin(); it != _traps.end(); ++it)
	{
		if (IntersectRect(&_rect, &_player->_rect, &(*it)->_rect))
		{
			(*it)->_isDestroy = true;
			_player->_speed -= 10;
		};
	}

	//충돌처리 끝


	// list Update

	for (auto it = _bullets.begin(); it != _bullets.end();)
	{
		(*it)->Update(deltaTime);
		if ((*it)->_isDestroy)
		{
			delete (*it);
			it = _bullets.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = _hampos.begin(); it != _hampos.end();)
	{
		(*it)->Update(deltaTime);
		if (existEnemy)
			(*it)->_isRand = true;
		if ((*it)->_isDestroy)
		{
			delete(*it);
			it = _hampos.erase(it);
		}
		else
		{
			++it;
		}
	}
	
	for (auto it = _arras.begin(); it != _arras.end();)
	{
		(*it)->Update(deltaTime);
		if ((*it)->_isDestroy)
		{
			delete(*it);
			it = _arras.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto it = _enemys.begin(); it != _enemys.end();)
	{
		(*it)->Update(deltaTime);

		if (_player->_isAsist == true && (*it)->_sprite._position.x <= 1024 && (*it)->_sprite._position.y <= 768 && (*it)->_sprite._position.x >= 0 && (*it)->_sprite._position.y >= 0)
		{
			_effects.push_back(new Effect((*it)->_sprite._position));
			(*it)->_isDestroy = true;
		}

		if ((*it)->_isDestroy == true)
		{	
			_items.push_back(new Item((*it)->_sprite._position, rand() % 4));

			delete(*it);
			it = _enemys.erase(it);
		}
		else
		{
			++it;
		}
	}
	
	for (auto it = _items.begin(); it != _items.end(); )
	{
		(*it)->Update(deltaTime);
		if ((*it)->_isDestroy)
		{
			delete(*it);
			it = _items.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = _enemyBullets.begin(); it != _enemyBullets.end();)
	{
		(*it)->Update(deltaTime);
		if (_player->_isAsist == true && (*it)->_sprite._position.x <= 1024 && (*it)->_sprite._position.y <= 768 && (*it)->_sprite._position.x >= 0 && (*it)->_sprite._position.y >= 0)
		{
			_effects.push_back(new Effect((*it)->_sprite._position));
			(*it)->_isDestroy = true;
		}
		if ((*it)->_isDestroy)
		{
			delete(*it);
			it = _enemyBullets.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = _effects.begin(); it != _effects.end();)
	{
		(*it)->Update(deltaTime);
		if ((*it)->_isDestroy)
		{
			delete(*it);
			it = _effects.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = _traps.begin(); it != _traps.end();)
	{
		(*it)->Update(deltaTime);
		if ((*it)->_isDestroy)
		{
			delete(*it);
			it = _traps.erase(it);
		}
		else
			++it;
	}

	//list Update end.

	_player->Update(deltaTime);
	_boss->Update(deltaTime);
	_map->Update(deltaTime);
	_UI->Update(deltaTime);

	_score++;
	if (_score >= 99999)
		_score = 99999;

	_num[0]->Update(deltaTime);
	_num[1]->Update(deltaTime);
	_num[2]->Update(deltaTime);
	_num[3]->Update(deltaTime);
	_num[4]->Update(deltaTime);
	_num[5]->Update(deltaTime);
	_num[6]->Update(deltaTime);
	_num[7]->Update(deltaTime);
	_num[8]->Update(deltaTime);
};

void GameScene::Render()
{
	_map->Render();
	_boss->Render();
	_player->Render();
	

	for (auto it = _bullets.begin(); it != _bullets.end(); ++it)
	{
		(*it)->Render();
	}
	for (auto it = _hampos.begin(); it != _hampos.end(); ++it)
	{
		(*it)->Render();
	}
	for (auto it = _arras.begin(); it != _arras.end(); ++it)
	{
		(*it)->Render();
	}
	for (auto it = _enemyBullets.begin(); it != _enemyBullets.end(); ++it)
	{
		(*it)->Render();
	}
	for (auto it = _enemys.begin(); it != _enemys.end(); ++it)
	{
		(*it)->Render();
	}
	for (auto it = _effects.begin(); it != _effects.end(); ++it)
	{
		(*it)->Render();
	}
	for (auto it = _items.begin(); it != _items.end(); ++it)
	{
		(*it)->Render();
	}
	
	for (auto it = _items.begin(); it != _items.end(); ++it)
	{
		(*it)->Render();
	}

	for (auto it = _traps.begin(); it != _traps.end(); ++it)
	{
		(*it)->Render();
	}

	_UI->Render();
	_num[0]->Render();
	_num[1]->Render();
	_num[2]->Render();
	_num[3]->Render();
	_num[4]->Render();
	_num[5]->Render();
	_num[6]->Render();
	_num[7]->Render();
	_num[8]->Render();
};

void GameScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{

};

