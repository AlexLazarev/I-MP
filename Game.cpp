#include "Game.h"



Game::Game(){
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "I&MyProblems!");
	gameState = ShowingMenu;
}


Game::~Game()
{
}


void Game::Start() {
	sf::Texture tBg, tHero, tEn, tExp, tBullet, THealth, TWeapon;
	tBg.loadFromFile("images/1.png");
	tHero.loadFromFile("images/hero.png");
	tEn.loadFromFile("images/rock_small.png");
	tExp.loadFromFile("images/explosions/type_A.png");
	tBullet.loadFromFile("images/fire_blue.png");
	THealth.loadFromFile("images/health2.png");
	TWeapon.loadFromFile("images/set6.png");
	
	anim.create("bullet", tBullet, 0, 0, 32, 50, 16, 0.005, 32);
	anim.create("explosion", tExp, 0, 0, 50, 50, 20, 0.01, 50);
	anim.create("enemy", tEn, 0, 0, 64, 50, 16, 0.005, 64);
	anim.create("ship", tHero, 80, 80, 100, 100, 1, 0.005, 100);
	anim.create("health", THealth, 0, 0, 80, 80, 1, 0.005, 100);
	anim.create("set_red", TWeapon, 0, 0, 100, 100, 1, 0.005, 100);
	
	sf::Clock clock;
	window->setFramerateLimit(60);

	Player *player = new Player();
	player->create(anim, 50, 100, 0, 45);
	essence.push_back(player);

	for (int i = 0; i < ENEMY_COUNT; i++) {
		Enemy *e = new Enemy();
		e->create(anim, rand() % WIDTH, rand() % HEIGHT, rand() % 360, 25);
		essence.push_back(e);
	}


	while (window->isOpen()) {
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 800;

		if (time > 40) time = 40;

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Space) {
					Bullet *b = new Bullet();
					b->create(anim, player->getX(), player->getY(), player->getAngle(), BULLET_RADIUS);
					essence.push_back(b);
				}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player->key["R"] = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))player->key["L"] = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) player->key["Up"] = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { player->key["Space"] = true; };

		for (auto i : essence)
			for (auto j : essence)
				if (i->collision(j)) {
					if (i->getName() == "bullet" && j->getName() == "enemy") {
					//	printf("x: %f y: %f\n", j->getX(),j->getY());
						
						i->damage(1);
						j->damage(1);
						if (j->getDead()) {
							Booty *b = new Booty();
							b->create(anim, j->getX(), j->getY(), 0, 16);
							essence.push_back(b);
						}
					}
					else if (i->getName() == "player" && j->getName() == "enemy") {
					}
				}

		for (auto i = essence.begin(); i != essence.end(); ) {
			Essentiality *e = *i;
			e->update(time);

			if (e->getDead()) {
				i = essence.erase(i);
				delete e;
			}  /// kxm
			else i++;
		}


		window->clear();

		for (auto i : essence)
			i->draw(window);



		window->display();
	}

}


void Game::ShowMenu() {
		Menu menu(WIDTH, HEIGHT);
		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event)) {
				switch (event.type) {
				case sf::Event::KeyReleased:
					switch (event.key.code) {
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;
					case sf::Keyboard::Down:
						menu.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (menu.GetPressedItem()){
						case 0:	
							gameState = Playing;
							return;
						case 1:
							break;
						case 2:
							window->close();
							break;
						}
					}
					break;
				case sf::Event::Closed:
					window->close();
					break;
				}
			}
	
			window->clear();
			menu.draw(window);
			window->display();
		}
}

void Game::Loop() {
	while (window->isOpen()) {
		switch (gameState) {
		case ShowingMenu:
			ShowMenu();
			break;
		case ShowingSplash:
			//	ShowSplashScreen();
			break;
		case ShowingWin:
			//ShowWinScreen();
			break;
		case Playing:
			Start();
			break;
		}
	}
}