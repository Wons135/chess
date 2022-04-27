#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#define OPTIONS 3


class Menu
{
public:
	Menu(float height, float width);
	~Menu();

	void draw(sf::RenderWindow& window);
	void navUp();
	void navDown();
	int pick();

private:
	int optionID;
	sf::Font font;
	sf::Text menu[OPTIONS];

};

