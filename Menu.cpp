#include "Menu.h"

Menu::Menu() {

}

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("font/BLACK_WATER_CRE.ttf")) {
		printf("Шрифт не загружен");
	}
	for (int i = 0; i < amountElements; i++) {
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setPosition(sf::Vector2f(width / 2.3, height/4 + i*50));
		text[i].setCharacterSize(40);
	}
	text[0].setString("PLAY");
	text[1].setString("OPTION");
	text[2].setString("EXIT");

}
Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) {
	for(int i = 0; i < amountElements; i++)
		window.draw(text[i]);
}

