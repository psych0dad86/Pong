#pragma once
#include "Window.hpp"
class CustomFont
{
public:
	CustomFont();
	CustomFont(const unsigned int& charSize, const sf::Vector2f(position));
	~CustomFont();
	const sf::Text& GetTextAdress()const;
	void setName(const std::string& label);
	void Update(const unsigned int& charSize, const sf::Vector2f(position));

private:
	sf::Font _font;
	sf::Text _text;
};

