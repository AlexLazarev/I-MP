#include "Enemy.h"



Enemy::Enemy(){
	dx = rand() % 10 - 5;
	dy = rand() % 10 - 5;
	STATE = normal;
	name = "enemy";
}


Enemy::~Enemy()
{
}

void Enemy::Animation(float time)
{
	float r = rand() % 5;
	if (STATE == explosion) {
		anim.set("explosion");
		name = "explosion";
		dx = 0;
		dy = 0;
		if (anim.End()){
			int r = rand() % 10;
			if (r < 6) {
				STATE = bun;
				if (r < 3) {
					anim.set("health");
					name = "health";
				}
				else {
					anim.set("weapon");
					name = "weapon";
				}
			}
			else life = 0;
		}
	}
	
	if (STATE == stay) anim.set("stay");
	if (STATE == normal) anim.set("enemy");
	anim.setRotate(angle);
	anim.tick(time*r);
}

void Enemy::update(float time) {
	Animation(time);
	x += dx;
	y += dy;
	if (x > WIDTH) x = 0;
	if (y > HEIGHT) y = 0;
	if (x < 0) x = WIDTH;
	if (y < 0) y = HEIGHT;
}

void Enemy::dead() {
	STATE = explosion;
	//life = 0;
}