#include "Menu.h"

Menu::Menu() {

}

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("font/BLACK_WATER_CRE.ttf")) {
		printf("Шрифт не загружен");
	}
	for (int i = 0; i < amountMenuItem; i++) {
		item[i].setFont(font);
		
		if (i != 0)
			item[i].setFillColor(sf::Color::White);
		else
			item[i].setFillColor(sf::Color::Red);
		item[i].setPosition(sf::Vector2f(width / 2.3, height/4 + i*50));
		item[i].setCharacterSize(40);
	}
	item[0].setString("PLAY");
	item[1].setString("OPTION");
	item[2].setString("EXIT");
	selectedItemIndex = 0;
}
Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow *&window) {
	for(int i = 0; i < amountMenuItem; i++)
		window->draw(item[i]);
}

void Menu::MoveUp(){
	if (selectedItemIndex - 1 >= 0) {
		item[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		item[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < amountMenuItem) {
		item[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		item[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
