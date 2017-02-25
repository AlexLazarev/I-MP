#pragma once
#include "SFML/Graphics.hpp"


class Score
{
	sf::Font font;
	sf::Text textScore[2];
	int score;
public:
	Score(float width, float height);
	~Score();
	void setScore(int s);
	void draw(sf::RenderWindow *&window);
};

