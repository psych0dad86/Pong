#include "Menu.hpp"



Menu::Menu()
{
	_buttonSize = sf::Vector2f(400, 100);

	Update(sf::Vector2u(0, 0));

	_menuFont[0].setName("Menu");
	_menuFont[1].setName("New Game");
	_menuFont[2].setName("1 VS 1");
	_menuFont[3].setName("Exit");
	
}

Menu::~Menu()
{
}

void Menu::Update(const sf::Vector2u windowsize)
{
	_backGrondSize.x = windowsize.x / 3;
	_backGrondSize.y = windowsize.y / 2;

	_PositionBackground.x = windowsize.x / 2;
	_PositionBackground.y = windowsize.y / 4;









	for (int i = 0; i < 4; ++i)
	{
		if (i == 0)
		{
			_shape[i].setSize(sf::Vector2f(_backGrondSize.x, _backGrondSize.y));
			_shape[i].setFillColor(sf::Color::Black);
			_shape[i].setOrigin(sf::Vector2f(_backGrondSize.x / 2 , 0 ));
			_shape[i].setPosition(sf::Vector2f(_PositionBackground.x, _PositionBackground.y));
			_menuFont[i].Update(90, sf::Vector2f(_PositionBackground.x, _PositionBackground.y));
		}
		else
		{
			_shape[i].setSize(sf::Vector2f(_buttonSize.x, _buttonSize.y));
			_shape[i].setFillColor(sf::Color::Red);
			_shape[i].setOrigin(sf::Vector2f(_buttonSize.x / 2, 0));
			_shape[i].setPosition(sf::Vector2f(_PositionBackground.x , _PositionBackground.y + (150 * i) - 80 ));
			_menuFont[i].Update(90, sf::Vector2f(_PositionBackground.x, _PositionBackground.y + (150 * i) - 80));

		}


	}
}

const sf::Text& Menu::GetAdress_menuFont(const int & i) const
{
	return _menuFont[i].GetTextAdress();
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

