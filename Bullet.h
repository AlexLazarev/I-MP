#pragma once
#include "Essentiality.h"
class Bullet :
	public Essentiality
{
	enum { explosion, normal, fly } STATE;
public:
	Bullet(char*);
	~Bullet();

	void update(float time);
	void Animation(float time);
	
};

