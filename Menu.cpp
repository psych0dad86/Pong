#include "Menu.hpp"



Menu::Menu()
{
	_buttonSize = sf::Vector2f(200, 50);
	Update(sf::Vector2u(0,0));
}

Menu::~Menu()
{
}

void Menu::Update(const sf::Vector2u windowsize)
{
	_backGrondSize.x = windowsize.x / 3;
	_backGrondSize.y = windowsize.y;


	for (int i = 0; i < 4; ++i)
	{
		if (i == 0)
		{
			_shape[i].setSize(sf::Vector2f(_backGrondSize.x, _backGrondSize.y));
			_shape[i].setFillColor(sf::Color::Black);
			_shape[i].setOrigin(sf::Vector2f(_backGrondSize.x / 2, 0));
			_shape[i].setPosition(sf::Vector2f(_backGrondSize.x * 1.5  , 0));
		}
		else
		{
			_shape[i].setSize(sf::Vector2f(_buttonSize.x, _buttonSize.y));
			_shape[i].setFillColor(sf::Color::Red);
			_shape[i].setOrigin(sf::Vector2f(_buttonSize.x / 2, 0));
			_shape[i].setPosition(sf::Vector2f(_backGrondSize.x * 1.5, 200 * i));


		}


	}
}

const sf::RectangleShape* Menu::GetMenuShape() const
{
	return _shape;
}

void Menu::SetUpbuttonPos(const sf::Vector2u windowsize)
{
	_backGrondSize.x = windowsize.x /3 ;
	_backGrondSize.y = windowsize.y;
}

