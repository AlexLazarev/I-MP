#include "Enemy.h"




Enemy::Enemy() {
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
		anim.set("explosion_B");
		name = "explosion";
		dx = 0;
		dy = 0;
		if (anim.End())
			dead = true;
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

	aim();

	if (life <= 0)
		STATE = explosion;
	if (x > WIDTH) x = 0;
	if (y > HEIGHT) y = 0;
	if (x < 0) x = WIDTH;
	if (y < 0) y = HEIGHT;
}

void Enemy::aim() {
	float x1, y1;
	x1 = target->getX() - x;
	y1 = target->getY() - y;
	angle = (atan2(y1, x1)) * 180 / M_PI;
//	printf("%f\n", angle);
}

void Enemy::setTarget(const Essentiality *newTarget) {
	target = newTarget;
}