#include "Header.h"

Sprite::Sprite()
{
	_zDepthPosition = D3DXVECTOR3(0, 0, 0);
	_position = D3DXVECTOR2(0, 0);
	_rotateCen = D3DXVECTOR2(0, 0);
	_rotate = 0;
	_scaleCen = D3DXVECTOR2(0, 0);
	_scale = D3DXVECTOR2(1, 1);
	_center = D3DXVECTOR2(0, 0);
	
	_a = _r = _g = _b = 255;

	_isAnimation = false;
	_isRepeat = false;
	_isAniEnd = false;
	_isSetCamera = false;

	_scene = 0;
	_maxScene = 0;

	_animationTime = 0;
	_aniStackTime = 0;
}

void Sprite::Update(float deltaTime)
{
	D3DXMatrixIdentity(&_matrix);
	D3DXVECTOR2 pos = _position;
	pos -= _center;

	if (!_isSetCamera)
	{
		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0.0f, &_scale, &_rotateCen, D3DXToRadian(_rotate), &pos);
	}
	else
	{
		D3DXVECTOR2 cameraPos = _position - _g_Camera->GetPos();
		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0.0f, &_scale, &_rotateCen, D3DXToRadian(_rotate), &cameraPos);
	}

	if (_isAnimation)
	{
		_aniStackTime += deltaTime;
		if (_aniStackTime >= _animationTime)
		{
			_aniStackTime = 0;
			if (++_scene > _maxScene)
			{
				if (_isRepeat)
				{
					_scene = 0;
				}
				else
				{
					--_scene;
					_isAniEnd = true;
				}
			}
		}
	}
}

void Sprite::Render(Texture* texture)
{
	g_Sprite->SetTransform(&_matrix);
	g_Sprite->Draw(texture->GetTexture(_scene), NULL, NULL, &_zDepthPosition, D3DCOLOR_ARGB(_a, _r, _g, _b));
}

void Sprite::SetAnimation(bool repeat, int scene, float time)
{
	_isAnimation = true;
	_isRepeat = repeat;
	_isAniEnd = false;

	_scene = 0;
	_maxScene = scene;

	_animationTime = time;
	_aniStackTime = 0;
}

void Sprite::SetCamera()
{
	_isSetCamera = true;
}

void Sprite::SetDepth(float depth)
{
	_zDepthPosition.z = depth;
}