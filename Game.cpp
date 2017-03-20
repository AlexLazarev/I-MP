#include "Game.h"



Game::Game(){
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "I&MyProblems!");
	gameState = ShowingMenu;
	
}


Game::~Game()
{
}


void Game::Start() {
	
	sf::Music music;
	music.openFromFile("audio/game.ogg");

	sf::Texture tBg, tHero, tHero2, tHero3, tMeteorite, tExpA, tExpB, tExpC, tBulletRed, tBulletBlue, THealth, TWeapon, tHeroFly, TEnemy;
	
	tBg.loadFromFile("images/bg.jpg");
	sf::Sprite bg;
	bg.setTexture(tBg);


	tMeteorite.loadFromFile("images/rock_small.png");
	
	THealth.loadFromFile("images/health2.png");
	TWeapon.loadFromFile("images/set6.png");
	TEnemy.loadFromFile("images/ship/enemy_type_A.png");

	//Texture bullet
	tBulletRed.loadFromFile("images/fire_red.png");
	tBulletBlue.loadFromFile("images/fire_blue.png");

	//Texture explosion
	tExpA.loadFromFile("images/explosions/type_A.png");
	tExpB.loadFromFile("images/explosions/type_B.png");
	tExpC.loadFromFile("images/explosions/type_C.png");

	//Texture hero
	tHero.loadFromFile("images/ship/light_hero_set1.png");
	tHero2.loadFromFile("images/ship/set2.png");
	tHero3.loadFromFile("images/ship/set3.png");
	

	//Animation explosion
	anim.create("explosion_A", tExpA, 0, 0, 147, 150, 20, 0.015, 147);
	anim.create("explosion_B", tExpB, 0, 0, 128, 150, 64, 0.015, 128);
	anim.create("explosion_C", tExpC, 0, 0, 150, 150, 48, 0.015, 150);
	
	//Animation bullet
	anim.create("bullet_red", tBulletRed, 0, 0, 32, 50, 16, 0.005, 32);
	anim.create("bullet_blue", tBulletBlue, 0, 0, 32, 50, 16, 0.005, 32);

	//Animation hero
    //anim.create("hero", tHero, 80, 80, 100, 100, 1, 0.005, 100);
	anim.create("light_hero", tHero,0, 0, 150, 150, 19, 0.009, 150);
	

	anim.create("set2", tHero2, 0, 0, 100, 100, 1, 0.0005, 100);
	anim.create("set3", tHero3, 0, 0, 100, 100, 1, 0.0005, 100);


	anim.create("meteorite", tMeteorite, 0, 0, 64, 50, 16, 0.005, 64);

	anim.create("enemy", TEnemy, 80, 80, 100, 100, 1, 0.005, 100);
	anim.create("health", THealth, 0, 0, 80, 80, 1, 0.005, 100);
	//anim.create("set_red", TWeapon, 0, 0, 100, 100, 1, 0.005, 100);
	
	sf::Clock clock;
	window->setFramerateLimit(60);
	float timeShootEnemy = 0;
	float timeShootPlayer = 0;
	float timeSpawn = 0;

	Player *player = new Player();
	player->create(anim, 50, 100, 0, 45);
	essence.push_back(player);

	for (int i = 0; i < ENEMY_COUNT; i++) {
		Enemy *e = new Enemy();
		e->create(anim, rand() % WIDTH, rand() % HEIGHT, 90, 45);
		e->setTarget(player);  // static  - ERROR
		essence.push_back(e);
	}


	for (int i = 0; i < METEORITE_COUNT; i++) {
		Meteorite *m = new Meteorite();	
		m->create(anim, rand() % WIDTH, rand() % HEIGHT, rand() % 360, 25);
		essence.push_back(m);
	}

	if(musicOn)
		music.play();
	
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
				

				timeShootPlayer += time;
				if (event.key.code == sf::Keyboard::Space) {
					if (timeShootPlayer > PLAYER_SPEED_ATTACK) {
						Bullet *b = new Bullet("hero_bullet", player->getWeapon());
						b->create(anim, player->getX(), player->getY(), player->getAngle(), BULLET_RADIUS);
						essence.push_back(b);
						timeShootPlayer = 0;
					}
				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player->key["R"] = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))player->key["L"] = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) player->key["Up"] = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { player->key["Space"] = true; };

			timeSpawn += time;
			if (timeSpawn > ENEMY_SPEED_SPAWN) {
				for (int i = 0; i < 3; i++) {
					Enemy *e = new Enemy();
					e->create(anim, rand()%2*WIDTH, rand()%2*HEIGHT, 90, 45);
					e->setTarget(player);  // static  - ERROR
					essence.push_back(e);
				}
				timeSpawn = 0;
			}

			

			timeShootEnemy += time;
			if (timeShootEnemy > 1000) {
				for (auto i : essence)
					if (i->getName() == "enemy") {
						Bullet *b = new Bullet("enemy_bullet", i->getWeapon());
						b->create(anim, i->getX(), i->getY(), i->getAngle(), BULLET_RADIUS);
						essence.push_back(b);
					}
				timeShootEnemy = 0;
			}




			for (auto i : essence)
				for (auto j : essence)
					if (i->collision(j)) {
						if (i->getName() == "hero_bullet" && (j->getName() == "enemy" || j->getName() == "meteorite")) {
							//	printf("x: %f y: %f\n", j->getX(),j->getY());
							i->attack(j);
							j->attack(i);
							player->setExp(60);
							score.addScore(10);
						}
						else if (i->getName() == "player" && (j->getName() == "enemy" || j->getName() == "meteorite")) {
							i->attack(j);
							j->attack(i);
							score.addScore(10);
						}
						else if (i->getName() == "enemy_bullet" && j->getName() == "player") {
							i->attack(j);
							j->attack(i);
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
			window->draw(bg);

			for (auto i : essence)
				i->draw(window);

			score.draw(window);

			if (player->getLife() < 0) {
				gameState = GameOver;
				return;
			}

			player->drawBar(window);

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
							gameState = ShowingOption;
							return;
						
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

void Game::ShowGameOver(){
	sf::Texture tGameOver;
	tGameOver.loadFromFile("images/GameOver.png");
	sf::Sprite bg;
	bg.setTexture(tGameOver);
	sf::Font font;
	sf::Text text;

	font.loadFromFile("font/Beast-Impacted.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(175);
	text.setPosition(sf::Vector2f(WIDTH*0.43, HEIGHT*0.6));
	text.setString(std::to_wstring(score.getScore()));


	while (window->isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ gameState = ShowingMenu; return; }
		window->clear();
		window->draw(bg);
		window->draw(text);
		window->display();
	}
}

void Game::ShowOption() {
	sf::Font font;
	sf::Text text;
	font.loadFromFile("font/bignoodletoo.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(75);
	text.setPosition(sf::Vector2f(WIDTH*0.35, HEIGHT*0.4));
	

	while (window->isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { gameState = ShowingMenu; return; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { musicOn = false; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { musicOn = true; }

		if(musicOn)
			text.setString("Music: ON");
		else
			text.setString("Music: OFF");

		window->clear();
		window->draw(text);
		window->display();
	}
}

void Game::loop() {
	while (window->isOpen()) {
		switch (gameState) {
		case ShowingMenu:
			ShowMenu();
			break;
		case ShowingOption:
			ShowOption();
			break;
		case ShowingSplashScene:
			//	ShowSplashScreen();
			break;
		case GameOver:
			ShowGameOver();
			break;
		case Playing:
			Start();
			break;
		}
	}
}