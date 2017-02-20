#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Menu.h"
#include <list>

class Game
{
	enum { ShowingSplash, ShowingMenu, ShowingWin, Playing} gameState;
	sf::RenderWindow *window;
	AnimationManager anim;
	std::list<Essentiality*> essence;
public:
	Game();
	~Game();
	void Start();
	void Loop();
	void ShowMenu();
	
};

