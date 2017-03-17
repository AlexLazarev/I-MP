#pragma once

#include "Essentiality.h"


class Player : public Essentiality
{
	enum { explosion, normal, fly } STATE;

	unsigned int lvl;
	char* ship;

	unsigned int experience;

	bool thrust = false;
	sf::RectangleShape lifeBar;
public:

	bool shoot, hit;
	std::map<std::string, bool> key;

	void KeyCheck();
	void Animation(float time);
	void update(float time);
	void drawBar(sf::RenderWindow *&window);
	void lvlUp();
	void setExp(unsigned int exp) { experience += exp; }
	
	Player();
	~Player();
};

