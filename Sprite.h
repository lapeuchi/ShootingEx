#pragma once

class Sprite
{
public:
	D3DXMATRIX _matrix;
	D3DXVECTOR3 _zDepthPosition;
	D3DXVECTOR2 _position;
	D3DXVECTOR2 _rotateCen;
	float _rotate;
	D3DXVECTOR2 _scaleCen;
	D3DXVECTOR2 _scale;
	D3DXVECTOR2 _center;

	int _a, _r, _g, _b;

	bool _isAnimation;
	bool _isRepeat;
	bool _isAniEnd;
	bool _isSetCamera;

	int _scene;
	int _maxScene;

	float _animationTime;
	float _aniStackTime;

	Sprite();
	void Update(float deltaTime);
	void Render(Texture* texture);

	void SetAnimation(bool repeat, int scene, float time);
	void SetCamera();
	void SetDepth(float depth);
};