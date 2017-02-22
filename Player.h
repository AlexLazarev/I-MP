#pragma once

#include "Essentiality.h"


class Player : public Essentiality
{
	bool thrust = false;	
public:

	bool shoot, hit;
	std::map<std::string, bool> key;

	void KeyCheck();
	void Animation(float time);
	void update(float time);
	Player();
	~Player();
};

