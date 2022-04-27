#include "Menu.h"
#include<iostream>

Menu::Menu(float height, float width) {

	try {
		if (!font.loadFromFile("gameplay.ttf")) {
			throw 420;
		}
	}
	catch(int err){
		std::cout << "Font not found." << err;
	}
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setCharacterSize(48);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width/2, height / (OPTIONS + 1)));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Blue);
	menu[1].setCharacterSize(48);
	menu[1].setString("Load");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (OPTIONS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Blue);
	menu[2].setCharacterSize(48);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (OPTIONS + 1) * 3));

	optionID = 0;
}

Menu::~Menu() {};

void Menu::draw(sf::RenderWindow& window) {

	for (int i = 0; i < OPTIONS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::navUp() {

	if (optionID - 1 >= 0) {
		menu[optionID].setFillColor(sf::Color::Blue);
		optionID--;
		menu[optionID].setFillColor(sf::Color::White);

	}
}

void Menu::navDown() {
	
	if(optionID + 1 < OPTIONS) {
		menu[optionID].setFillColor(sf::Color::Blue);
		optionID++;
		menu[optionID].setFillColor(sf::Color::White);

	}
}

int Menu::pick() {
	return optionID;
}