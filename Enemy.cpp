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
	if (STATE == explosion) anim.set("explosion");
	if (STATE == stay) anim.set("stay");
	if (STATE == normal) anim.set("enemy");
	anim.setRotate(angle);
	anim.tick(time*r);
}

void Enemy::update(float time) {
	Animation(time);
	x += dx;
	y += dy;
	if (x > W) x = 0;
	if (y > H) y = 0;
	if (x < 0) x = W;
	if (y < 0) y = H;
}

void Enemy::dead() {
	STATE = explosion;
	//life = 0;
}