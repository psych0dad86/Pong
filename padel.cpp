#include "padel.hpp"

Padel::Padel()
{
	_padle.setSize(sf::Vector2f(50, 200));
	_padle.setOrigin(sf::Vector2f(0, 100));
	_padle.setOutlineColor(sf::Color::Black);
	_padle.setOutlineThickness(5);

	_direction = None;
	_speed = 0.5;
	
}

Padel::~Padel()
{
}

void Padel::SetPosition(const sf::Vector2f&  position)
{
	_padle.setPosition(position);
}

void Padel::SetOriging(const sf::Vector2f& position)
{
	_padle.setOrigin(position);
}

const sf::RectangleShape& Padel::GetShapeAdress() const
{
	return _padle;
}

void Padel::SetDirection(const Direction direction)
{
	_direction = direction;
}

void Padel::Move(const float& elapsed, const sf::Vector2u& windowsize)
{
	switch (_direction)
	{
	case(Direction::Up): 
		if (_padle.getPosition().y > 105)
			_padle.setPosition(this->GetPosition().x, this->GetPosition().y - (_speed * elapsed));
		else 
			_padle.setPosition(this->GetPosition().x, 105);
		break;
	case(Direction::Down): 
		if (_padle.getPosition().y < windowsize.y - 105)
			_padle.setPosition(this->GetPosition().x, this->GetPosition().y + (_speed * elapsed));
		else
			_padle.setPosition(this->GetPosition().x, windowsize.y - 105);
		break;
	case(Direction::None): break;
	default: std::cout << "Something get Wrong, no UP, Down or None" << std::endl;
	}
}

sf::Vector2f Padel::GetPosition()
{
	return _padle.getPosition();
}
