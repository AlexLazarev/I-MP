#pragma once
#include "Essentiality.h"
class Enemy :
	public Essentiality
{
	
public:
	Enemy();
	~Enemy();
	void update(float time);
	void Animation(float time);
	void dead();
};

