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
	Update(charSize, position);

}

CustomFont::~CustomFont()
{
}

const sf::Text& CustomFont::GetTextAdress() const
{
	return _text;
}

void CustomFont::setName(const std::string& label)
{
	_text.setString(label);
}

void CustomFont::Update(const unsigned int& charSize, const sf::Vector2f(position))
{


	_text.setFont(_font);
	_text.setCharacterSize(charSize);
	//_text.setColor(sf::Color::Green);
	_text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
	_text.setPosition(position);

}
