#pragma once
#include <SFML/Graphics.hpp>
#include "SETTING.h"
class Animation
{
	bool end;
public:
	std::vector<sf::IntRect> frames; 
	float currentFrame, speed;
	bool isPlaying;
	sf::Sprite sprite;
	float rotate;
	Animation();
	~Animation();
	bool End();

	void tick(float time);
};

