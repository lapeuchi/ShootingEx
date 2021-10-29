#include "Header.h"

Loading::Loading()
{
	bIsLoading = false;
	bIsFadeIn = false;
	loadTime = 0;
	loadTimer = 0;

	_sprite = Sprite();
	_sprite._a = 0.f;
}

void Loading::Update(float deltaTime)
{
	if (bIsLoading)
	{
		if (bIsFadeIn)
		{
			_sprite._a += 255.f * deltaTime;
			if (_sprite._a >= 255)
			{
				_sprite._a = 255;
				loadTimer += deltaTime;
				if (loadTimer >= loadTime)
				{
					bIsFadeIn = false;
					delete _g_Scene;
					_g_Scene = _scene;
				}
			}
		}
		else
		{
			_sprite._a -= 255.f * deltaTime;
			if (_sprite._a <= 0)
			{
				_sprite._a = 0;
				bIsLoading = false;
			}
		}
	}
	_sprite.Update(deltaTime);
}

void Loading::Render()
{
	_sprite.Render(_g_Asset->GetTexture("Loading"));
}

void Loading::LoadScene(Scene* scene)
{
	if (!bIsLoading)
	{
		bIsLoading = true;
		bIsFadeIn = true;
		loadTimer = 0;
		_scene = scene;
	}
}