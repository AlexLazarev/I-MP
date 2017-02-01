#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <list>
using namespace sf;

bool collision(Essentiality *a, Essentiality *b) {
	return sqrt((b->x - a->x)*(b->x - a->x) + (b->y - a->y)*(b->y - a->y)) < (a->r + b->r);
}

int main()
{
	Clock clock;

	sf::RenderWindow window(sf::VideoMode(1200, 800), "I&MP");
	window.setFramerateLimit(60);
	sf::Texture tBg, tHero, tEn, tExp, tBullet;

	tBg.loadFromFile("images/1.png");
	tHero.loadFromFile("images/hero.png");
	tEn.loadFromFile("images/rock_small.png");
	tExp.loadFromFile("images/explosions/type_A.png");
	tBullet.loadFromFile("images/fire_blue.png");
	AnimationManager anim;
	anim.create("bullet", tBullet, 0, 0, 32, 50, 16, 0.005, 32);
	anim.create("explosion", tExp, 0, 0, 50, 50, 20, 0.015, 50);
	anim.create("enemy", tEn, 0, 0, 64, 50, 16,0.005, 64);
	anim.create("ship", tHero, 80, 80, 100, 100, 1, 0.005, 100);
	
	
	std::list<Essentiality*> essence;
	Player *player = new Player();
	player->create(anim, 50, 100, 0, 50);
	essence.push_back(player);
	for (int i = 0; i < ENEMY_COUNT; i++) {
		Enemy *e = new Enemy();
		e->create(anim, rand() % W, rand() % H, rand()%360,32);
		essence.push_back(e);
	}

	
while (window.isOpen())	{

	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 800;  // здесь регулируем скорость игры

	if (time > 40) time = 40;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space) {
					Bullet *b = new Bullet();
					b->create(anim, player->x, player->y,player->angle,16);
					essence.push_back(b);
			}

		}
		
			if (Keyboard::isKeyPressed(Keyboard::Right)) player->key["R"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Left))player->key["L"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Up)) player->key["Up"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Down))player->key["Down"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Space)) { player->key["Space"] = true; };

		for (auto i : essence)
			for (auto j : essence) 
				if (collision(i, j)) {
					if (i->getName() == "bullet" && j->getName() == "enemy") {
						i->life = 0;
						j->life = 0;

					}
					else if (i->getName() == "player" && j->getName() == "enemy") {
						//i->life--;
						j->life = 0;
					}
				}
			
		for (auto i = essence.begin(); i != essence.end(); ) {
			Essentiality *e = *i;
			e->update(time);
			
			if (e->life == false) {
				i = essence.erase(i);
				delete e;
			}  /// kxm
			else i++;
		}


		window.clear();
		
		for (auto i : essence) 
			i->draw(window);
		
		window.display();
	}

	return 0;
}
