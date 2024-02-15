#include "Menu.hpp"



Menu::Menu()
{
	_buttonSize = sf::Vector2f(400, 100);
	_CharSize = 80;
	Update(sf::Vector2u(0, 0));


	_selectedButton = Button::NEW_GAME;
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
			_shape[i].setOutlineColor(sf::Color::White);
			_shape[i].setOutlineThickness(3);
			_menuFont[i].Update(_CharSize, sf::Vector2f(_PositionBackground.x, _PositionBackground.y - 50), sf::Color::White);			
		}
		else
		{
			_shape[i].setSize(sf::Vector2f(_buttonSize.x, _buttonSize.y));
			_shape[i].setFillColor(sf::Color::Red);
			_shape[i].setOrigin(sf::Vector2f(_buttonSize.x / 2, 0));
			_shape[i].setOutlineColor(sf::Color::White);
			_shape[i].setOutlineThickness(3);
			_shape[i].setPosition(sf::Vector2f(_PositionBackground.x , _PositionBackground.y + (150 * i) - 80 ));
			_menuFont[i].Update(_CharSize, sf::Vector2f(_PositionBackground.x, _PositionBackground.y + (150 * i) - 50), sf::Color::White);

		}
	}

	switch (_selectedButton)
	{
	case Button::NEW_GAME:
		_menuFont[1].ChangeColor(sf::Color::Green);
		break;
	case Button::ONE_VS_ONE:
		_menuFont[2].ChangeColor(sf::Color::Green);
		break;
	case Button::_EXIT:
		_menuFont[3].ChangeColor(sf::Color::Green);
		break;
	default:
		_menuFont[0].ChangeColor(sf::Color::Yellow);
		break;
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

void Menu::SetSelectedButton(const sf::Keyboard::Key& button)
{
	if (button == sf::Keyboard::Up)
	{
		if (_selectedButton == Button::NEW_GAME)
		{
			_selectedButton = Button::_EXIT;
		}
		else
		{
			_selectedButton = static_cast<Button>(static_cast<int>(_selectedButton) - 1);
		}
	}
	else if (button == sf::Keyboard::Down)
	{
		if (_selectedButton == Button::_EXIT)
		{
			_selectedButton = Button::NEW_GAME;
		}
		else
		{
			_selectedButton = static_cast<Button>(static_cast<int>(_selectedButton) + 1);
		}
	}
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const

{
	for (int i = 0; i < 4; i++)
	{
		target.draw(_shape[i], states);
		target.draw(_menuFont[i], states);


	}
}



