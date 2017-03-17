#pragma once
#include "Essentiality.h"
#include "Bullet.h"
class Enemy :
	public Essentiality	
{
	enum { explosion, normal } STATE;
	
	const Essentiality *target;
	
public:
	Enemy();
	~Enemy();
	void update(float time);
	void Animation(float time);
	void aim();


	void setTarget(const Essentiality *newTarget);
};

