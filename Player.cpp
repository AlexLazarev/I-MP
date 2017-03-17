#include "Player.h"



Player::Player(){
	name = "player";
	ship = "hero";
	shoot = false;
	lvl = 1;
	STATE = normal;
	WEAPON = BLAST_RED;
	speed = 30;
	dmg = PLAYER_DAMAGE;
	life = PLAYER_MAX_LIFE;
	lifeBar.setFillColor(sf::Color(185,1,1));
	lifeBar.setSize(sf::Vector2f(life,10));
	lifeBar.setPosition(WIDTH*0.1, HEIGHT*0.02);
}


Player::~Player()
{
}



void Player::KeyCheck() {

	if (key["L"])	{
		angle -= 4;
	}

	if (key["R"]) {
		angle += 4;
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
	if (STATE == explosion){ anim.set("explosion_A"); 	
		if (anim.End())
			dead = true;
	}

	if (STATE == normal) {
		anim.set("light_hero");
		if(anim.End())
			STATE = fly;
	}

	anim.setRotate(angle);
	anim.tick(time);
}

void Player::update(float time) {
	KeyCheck();
	Animation(time);
	
	if (thrust) {
	//	STATE = fly;
		dx += cos(angle*DEGTORAD)*0.2;
		dy += sin(angle*DEGTORAD)*0.2;
	}
	else {
		STATE = normal;
		dx *= 0.9;
		dy *= 0.9;
	}

	float speed = sqrt(dx*dx + dy*dy);
	if (speed > MaxSpeed) {
		dx *= MaxSpeed / speed;
		dy *= MaxSpeed / speed;
	}

	if (x > WIDTH) x = 0;
	if (y > HEIGHT) y = 0;
	if (x < 0) x = WIDTH;
	if (y < 0) y = HEIGHT;

	x += dx;
	y += dy;
	if (life > 0)
		lifeBar.setSize(sf::Vector2f(life, 10));
	else
		STATE = explosion;
	if (experience > 100) {
		experience = 0;
		//lvlUp();
	}
	key["R"] = key["L"] = key["Up"] = key["Down"] = key["Space"] = false;
}

void Player::drawBar(sf::RenderWindow *&window) {
	window->draw(lifeBar);

}

 void Player::lvlUp() {
	++lvl;

	switch (lvl)	
	{
	case 2:
		ship = "set2";
		life = 1000;
		break;
	case 3:
		ship = "set3";
		life = 2000;
		break;
	default:
		break;
	}
	


}