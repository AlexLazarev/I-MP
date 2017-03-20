#pragma once
#include "SFML/Graphics.hpp"
#include "SETTING.h"


class Score
{
	sf::Font font;
	sf::Text textScore[2];
	int score;
public:
	Score();
	~Score();
	void addScore(int s);
	int getScore() { return score; }
	void draw(sf::RenderWindow *&window);
};

