#pragma once
#include <SFML/Graphics.hpp>
#include "SETTING.h"
class Animation
{
public:
	std::vector<sf::IntRect> frames; // flip - povernytue izobrajeniya - dl9 zerkalnoi animacii
	float currentFrame, speed;
	bool isPlaying;
	sf::Sprite sprite;
	float rotate;
	Animation();
	~Animation();
	void tick(float time);
};

