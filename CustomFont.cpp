#include "CustomFont.hpp"



CustomFont::CustomFont()
{
	_font.loadFromFile("Namecat.ttf");
	if (!_font.loadFromFile("Namecat.ttf"))
	{
		std::cout << "Error cant load Font" << std::endl;
	}
	_text.setString("ZERO");
}

CustomFont::CustomFont(const unsigned int& charSize,const sf::Vector2f(position))
{
	_font.loadFromFile("Namecat.ttf");
	if (!_font.loadFromFile("Namecat.ttf"))
		std::cout << "Error cant load Font" << std::endl;
	Update(charSize, position, sf::Color::White);

}

CustomFont::~CustomFont()
{
}


void CustomFont::setName(const std::string& label)
{
	_text.setString(label);
}

void CustomFont::Update(const unsigned int& charSize, const sf::Vector2f(position), const sf::Color& color)
{


	_text.setFont(_font);
	_text.setCharacterSize(charSize);
	_text.setFillColor(color);
	_text.setOutlineColor(sf::Color::Black);
	_text.setOutlineThickness(3);
	_text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
	_text.setPosition(position);

}

void CustomFont::ChangeColor(const sf::Color& color)
{
	_text.setFillColor(color);
}


void CustomFont::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_text);
}
