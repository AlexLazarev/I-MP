#include "Bullet.h"



Bullet::Bullet(){
	name = "bullet";
	STATE = normal;
}



void Bullet::Animation(float time)
{	
	if (STATE == normal) anim.set("bullet");
	anim.setRotate(angle+90);
	anim.tick(time);
}

Bullet::~Bullet()
{
}

void Bullet::update(float time) {
	Animation(time);
	dx = cos(angle*DEGTORAD) * 6;
	dy = sin(angle*DEGTORAD) * 6;
	x += dx;
	y += dy;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		dead = true;
	if (life <= 0)
		dead = true;
}
