#pragma once
#include "Window.hpp"
class Menu
{
public:
	Menu();
	~Menu();


	void Update(const sf::Vector2u windowsize);

	const sf::RectangleShape* GetMenuShape() const;
	void SetUpbuttonPos(const sf::Vector2u windowsize);

private:
	sf::Vector2f _buttonSize;
	sf::Vector2f _backGrondSize;
	sf::Vector2f _buttonPos;
	sf::RectangleShape _shape[4];
};

