#pragma once

class Map
{
public:
	Sprite _sprite;
	float _speed;
	
	Map();
	
	void Update(float deltaTime);
	void Render();
};