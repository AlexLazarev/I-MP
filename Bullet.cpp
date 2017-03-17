#include "Bullet.h"



Bullet::Bullet(char* _name, weapon weapon){
	name = _name;
	WEAPON = weapon;
	dmg = 10;
}



void Bullet::Animation(float time)
{	
	switch (WEAPON)
	{
	case BLAST_BLUE:
		anim.set("bullet_blue");
		break;
	case BLAST_RED:
		anim.set("bullet_red");
		break;
	default:
		break;
	}
	

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

