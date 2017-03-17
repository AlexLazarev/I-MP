#pragma once
#include "AnimationManager.h"



class Essentiality
{
protected:
	
	enum weapon	{ BLAST_RED, BLAST_BLUE } WEAPON;

	char*			 name;
	float			 x, y, dx, dy;
	float			 angle;
	float			 speed;
	float			 r;
	float			 dmg;
	int              life;
	bool			 dead;
	AnimationManager anim;

	virtual void Animation(float time) = 0;
public:
	char* getName()		const	{ return name; }
	int getLife()		const	{ return life; }
	float getX()		const	{ return x; }
	float getY()		const	{ return y; }
	float getAngle()	const	{ return angle; }
	bool getDead()		const	{ return dead; }
	weapon getWeapon()  const	{ return WEAPON; }


	void attack(Essentiality *e);
	
	
	void create(AnimationManager a, float X, float Y, float Angle, float R);
	void draw(sf::RenderWindow *&window);

	bool collision(Essentiality *b);

	virtual void update(float time) = 0;
	
	


	Essentiality();
};


