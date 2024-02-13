#pragma once
#include "CustomFont.hpp"
class Menu
{
public:
	Menu();
	~Menu();


	void Update(const sf::Vector2u windowsize);
	const sf::Text& GetAdress_menuFont(const int& i) const;

	const sf::RectangleShape* GetMenuShape() const;
	void SetUpbuttonPos(const sf::Vector2u windowsize);

private:
	sf::Vector2f _buttonSize;
	sf::Vector2f _backGrondSize;
	sf::Vector2f _buttonPos;
	sf::Vector2f _PositionBackground;
	sf::RectangleShape _shape[4];
	CustomFont _menuFont[4];
};

