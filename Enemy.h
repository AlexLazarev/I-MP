#pragma once
#include "Essentiality.h"

class Enemy :
	public Essentiality	
{

	const Essentiality *target;
public:
	Enemy();
	~Enemy();
	void update(float time);
	void Animation(float time);
	void aim();
	void setTarget(const Essentiality *newTarget);
};

