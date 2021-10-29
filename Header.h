#pragma once

#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include <d3d9.h>
#include <d3dx9core.h>

#include <Windows.h>
#include <time.h>
#include <list>
#include <string>
#include <vector>
#include <map>

using std::list;
using std::string;
using std::vector;
using std::map;

#include "SingleTon.h"
#include "Application.h"
#include "Texture.h"
#include "Sprite.h"

#include "Scene.h"
#include "Loading.h"

#include "Bullet.h"
#include "Hampo.h"
#include "Arra.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

#include "Item.h"
#include "Trap.h"
#include "Effect.h"
#include "Trap.h"
#include "Map.h"
#include "UI.h"
#include "NUM.h"

#include "IntroScene.h"
#include "GameScene.h"
#include "EndingScene.h"

#include "Game.h"
