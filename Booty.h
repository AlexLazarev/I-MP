#pragma once
#include "Essentiality.h"

class Booty:
	public Essentiality
{
	enum { explosion, normal, fly } STATE;
public:
	Booty();
	~Booty();

	void update(float time);
	void Animation(float time);

};

