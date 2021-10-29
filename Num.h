#pragma once

class Num
{
public:
	Sprite _sprite;
	
	Num(D3DXVECTOR2 pos);
	~Num();

	void Update(float deltaTime);
	void Render();
	
};