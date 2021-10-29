#pragma once

class Loading
{
public:
	Loading();

	void Update(float deltaTime);
	void Render();
	void LoadScene(Scene* scene);

	Scene* _scene;
	Sprite _sprite;

	bool bIsLoading;
	bool bIsFadeIn;

	float loadTime;
	float loadTimer;
};