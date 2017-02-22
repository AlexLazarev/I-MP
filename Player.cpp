#include "Player.h"



Player::Player(){
	name = "player";
	shoot = false;
	STATE = normal;
	speed = 30;
	angle = 0;
	life = 2;
}


Player::~Player()
{
}



void Player::KeyCheck() {

	if (key["L"])	{
		angle -= 3;
	}

	if (key["R"]){
		angle += 3;	
	}

	if (key["Up"])	{
		thrust = true;
	}

	if (key["Space"]){
		//STATE = explosion;
		shoot = true;
	}

	/////////////////////если клавиша отпущена///////////////////////////

	if (!key["Up"])	{
		thrust = false;
	}

	if (!key["Space"]){
		shoot = false;
	}

	key["R"] = key["L"] = key["Up"] = key["Down"] = key["Space"] = false;
}



void Player::Animation(float time)
{
	if (STATE == explosion) anim.set("explosion");
	if (STATE == normal) anim.set("ship");
	anim.setRotate(angle);
	anim.tick(time);
}

void Player::update(float time) {
	KeyCheck();
	Animation(time);

	if (thrust) {
		dx += cos(angle*DEGTORAD)*0.2;
		dy += sin(angle*DEGTORAD)*0.2;

	}
	else {
		dx *= 0.9;
		dy *= 0.9;
	}

	float speed = sqrt(dx*dx + dy*dy);
	if (speed > MaxSpeed) {
		dx *= MaxSpeed / speed;
		dy *= MaxSpeed / speed;
	}


	x += dx;
	y += dy;
	if (life <= 0)
		dead = true;
	key["R"] = key["L"] = key["Up"] = key["Down"] = key["Space"] = false;
}
