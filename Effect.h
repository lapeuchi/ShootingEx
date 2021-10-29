#pragma once

class Effect
{
public:
	Sprite _sprite;
	
	Effect(D3DXVECTOR2 pos);
	~Effect();

	bool _isDestroy;

	void Update(float deltaTime);
	void Render();
};






