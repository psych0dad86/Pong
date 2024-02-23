#pragma once

#include "Ball.hpp"

class CustomFont : public sf::Drawable
{
public:
	CustomFont();
	CustomFont(const unsigned int& charSize, const sf::Vector2f(position));
	~CustomFont();

	void UpdateName(const std::string& label);
	void Update(const unsigned int& charSize, const sf::Vector2f(position), const sf::Color& color);
	void ChangeColor(const sf::Color& color);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Font _font;
	sf::Text _text;
};

