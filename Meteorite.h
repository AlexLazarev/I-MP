#pragma once
#include "Essentiality.h"
class Meteorite :
	public Essentiality
{
	enum { explosion, normal, fly } STATE;
	
public:
	Meteorite();
	~Meteorite();
	void update(float time);
	void Animation(float time);
	
};

