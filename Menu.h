#pragma once
#include "SFML/Graphics.hpp"
#define amountMenuItem 3
class Menu
{
	int selectedItemIndex;
	sf::Font				font;
	sf::Text				item[amountMenuItem];
	

public:
	Menu(float width, float height);

	int GetPressedItem()	{ return selectedItemIndex; }
	Menu();
	~Menu();

	void draw(sf::RenderWindow *&window); 
	void MoveUp();
	void MoveDown();
};

