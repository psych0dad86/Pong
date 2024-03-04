#pragma once
#include "Menu.hpp"

//typedef void (Padel::* ScoreChanger)();

enum Direction
{
	Up, Down, None
};
class Padel
{
public:
	Padel();
	~Padel();

	void SetPosition(const sf::Vector2f& position);

	void SetOriging(const sf::Vector2f& position);
	const sf::RectangleShape& GetShapeAdress() const;
	void SetDirection(const Direction direction);
	void Move(const float& elapsed, const sf::Vector2u& windowsize);
	const int& GetScore() const;
	sf::Vector2f GetPosition();
	void ChangeScore();
	void ResetScore();
	void AiSetDirection(const sf::Vector2f& position);

private:
	
	sf::RectangleShape _padle;
	int _score;
	float _speed;
	Direction _direction;
};

