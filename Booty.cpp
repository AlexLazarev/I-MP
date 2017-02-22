#include "Booty.h"



Booty::Booty(){
	name = "booty";
	STATE = normal;
}


Booty::~Booty()
{
}

void Booty::Animation(float time)
{
	if (STATE == normal) anim.set("health");
	anim.setRotate(angle);
	anim.tick(time);
}


void Booty::update(float time) {
	Animation(time);
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		life = 0;

}

