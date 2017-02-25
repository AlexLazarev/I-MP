#include "Score.h"



Score::Score(float width, float height)
{
	score = 0;
	font.loadFromFile("font/bignoodletoo.ttf");
	for (int i = 0; i < 2; i++) {
		textScore[i].setFont(font);
		textScore[i].setFillColor(sf::Color::White);	
		textScore[i].setCharacterSize(30);	
	}
	textScore[0].setPosition(sf::Vector2f(width*0.01, height*0.01));
	textScore[0].setString("Score");
	textScore[1].setPosition(sf::Vector2f(width*0.01, height*0.04));
	textScore[1].setString("0");
}

void Score::draw(sf::RenderWindow *&window) {
	for (int i = 0; i < 2; i++)
		window->draw(textScore[i]);
}

void Score::setScore(int s) {
	score += s;
	textScore[1].setString(std::to_wstring(score));
}

Score::~Score()
{
}
