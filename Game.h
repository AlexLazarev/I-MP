#pragma once
#include "Player.h"
#include "Meteorite.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Booty.h"
#include "Menu.h"
#include "Score.h"

#include <list>

class Game
{
	enum { ShowingSplashScene, ShowingMenu, GameOver, Playing} gameState;
	sf::RenderWindow*				window;
	AnimationManager				anim;
	std::list<Essentiality*>		essence;
	Score							score;
public:
	Game();
	~Game();
	void Start();
	void loop();
	void ShowMenu();
	void ShowGameOver();
	
};

