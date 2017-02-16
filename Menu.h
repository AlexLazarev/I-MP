#pragma once
#include "SFML/Graphics.hpp"
#define amountElements 3
class Menu
{
	int selectedItemIndex;
	sf::Font font;
	sf::Text text[amountElements];
	

public:
	Menu(float width, float height);


	Menu();
	~Menu();

	void draw(sf::RenderWindow &window); 
	//void MoveUp();
	//void MoveDown();
};

