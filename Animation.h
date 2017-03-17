#pragma once
#include <SFML/Graphics.hpp>
#include "SETTING.h"
class Animation
{
	bool						end;

public:

	std::vector<sf::IntRect>	frames; 
	float						currentFrame;
	float                       speed;
	float						rotate;
	bool						isPlaying;
	sf::Sprite					sprite;


	Animation();
	~Animation();
	bool End();

	void tick(float time);
};

