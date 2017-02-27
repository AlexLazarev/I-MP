#pragma once
#include "Essentiality.h"
class Meteorite :
	public Essentiality
{
	
public:
	Meteorite();
	~Meteorite();
	void update(float time);
	void Animation(float time);
	
};

