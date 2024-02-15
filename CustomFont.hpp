#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>


class CustomFont : public sf::Drawable
{
public:
	CustomFont();
	CustomFont(const unsigned int& charSize, const sf::Vector2f(position));
	~CustomFont();
	const sf::Text& GetTextAdress()const;
	void setName(const std::string& label);
	void Update(const unsigned int& charSize, const sf::Vector2f(position), const sf::Color& color);
	void ChangeColor(const sf::Color& color);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Font _font;
	sf::Text _text;
};

