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

	void Move(const float& elapsed, const sf::Vector2u& windowsize);
	const int& GetScore() const;
	sf::Vector2f GetPosition();
	void ChangeScore();
	void ResetScore();
	void AiSetDirection(const sf::Vector2f& position, const DirectionBall direction,
		const sf::Vector2f windowSize);
	void inputPlayer1();
	void inputPlayer2();

private:
	
	sf::RectangleShape _padle;
	int _score;
	float _speed;
	Direction _direction;
};

