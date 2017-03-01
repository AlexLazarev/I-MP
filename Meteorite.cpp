#include "Meteorite.h"



Meteorite::Meteorite(){
	dx = rand() % 10 - 5;
	dy = rand() % 10 - 5;
	STATE = normal;
	name = "enemy";
}


Meteorite::~Meteorite()
{
}

void Meteorite::Animation(float time)
{
	float r = rand() % 5;
	if (STATE == explosion) {
		anim.set("explosion_C");
		name = "explosion";
		dx = 0;
		dy = 0;
		if (anim.End())
			dead = true;
	}
	
//	if (STATE == stay) anim.set("stay");
	if (STATE == normal) anim.set("meteorite");
	anim.setRotate(angle);
	anim.tick(time*r);
}

void Meteorite::update(float time) {
	Animation(time);
	x += dx;
	y += dy;

	if (life <= 0)
		STATE = explosion;
	if (x > WIDTH) x = 0;
	if (y > HEIGHT) y = 0;
	if (x < 0) x = WIDTH;
	if (y < 0) y = HEIGHT;
}

