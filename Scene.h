#pragma once

class Scene
{
public:
	Scene() {};
	virtual ~Scene() {};

	virtual void Update(float deltaTime) {};
	virtual void Render() {};
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {}
};

extern Scene* _scene;
extern void LoadScene(Scene* scene);