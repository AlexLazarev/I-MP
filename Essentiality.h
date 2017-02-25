#pragma once
#include "AnimationManager.h"



class Essentiality
{
protected:
	enum { stay, explosion, normal, bun, fly} STATE;
	char *name;
	float x, y, dx, dy;
	float angle;
	float speed;
	float r;
	int life;
	bool dead;
	AnimationManager anim;

	virtual void Animation(float time) = 0;
public:
	char* getName()			{ return name; };
	int getLife()			{ return life; }
	float getX()			{ return x; }
	float getY()			{ return y; }
	float getAngle()		{ return angle; }
	bool getDead()			{ return dead; }
	
	void damage(int d)		{ life -= d; }
	
	
	void create(AnimationManager a, float X, float Y, float Angle, float R);
	void draw(sf::RenderWindow *&window);

	bool collision(Essentiality *b);

	virtual void update(float time) = 0;
	
	


	Essentiality();
};


