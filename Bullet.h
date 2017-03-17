#pragma once
#include "Essentiality.h"
class Bullet :
	public Essentiality
{
public:
	Bullet(char*, weapon);
	~Bullet();

	void update(float time);
	void Animation(float time);
	
};

