#include "Player.h"



Player::Player(){
	name = "player";
	shoot = false;
	STATE = normal;
	speed = 30;
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
	if (STATE == normal) anim.set("hero");
	if (STATE == fly) 
		anim.set("heroFly");
	anim.setRotate(angle);
	anim.tick(time);
}

void Player::update(float time) {
	KeyCheck();
	Animation(time);
	lifeBar.setSize(sf::Vector2f(life, 10));
	if (thrust) {
		//STATE = fly;
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


	x += dx;
	y += dy;
	if (life <= 0)
		dead = true;
	key["R"] = key["L"] = key["Up"] = key["Down"] = key["Space"] = false;
}

void Player::drawBar(sf::RenderWindow *&window) {
	window->draw(lifeBar);

}