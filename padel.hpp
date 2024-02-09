#pragma once
#include "Window.hpp"

enum Direction
{
	Up, Down, None
};
class Padel
{
public:
	Padel();
	~Padel();

	void SetPosition(const sf::Vector2f position);
	void SetOriging(const sf::Vector2f position);
	const sf::RectangleShape& GetShapeAdress() const;
	void SetDirection(const Direction direction);
	void Move(const float elapsed);
	
	sf::Vector2f GetPosition();

private:
	sf::RectangleShape _padle;
	Direction _direction;
};

