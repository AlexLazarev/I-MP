#pragma once
#include "AnimationManager.h"



class Essentiality
{
protected:
	enum { stay, explosion, normal, bun} STATE;
	char *name;
public:
	char* getName() { return name; };
	float x, y, dx, dy;
	float angle;
	float speed;
	float r;
	AnimationManager anim;
	int life;
	int dir;
	Essentiality();
	void create(AnimationManager a, float X, float Y, float Angle, float R);
	virtual void update(float time) = 0;
	virtual void Animation(float time) = 0;
	void draw(sf::RenderWindow &window);
	virtual void dead() = 0;
};


