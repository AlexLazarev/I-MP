#pragma once
#include "Essentiality.h"
class Bullet :
	public Essentiality
{
public:
	Bullet();
	~Bullet();

	void update(float time);
	void Animation(float time);
	void dead() {};
};

