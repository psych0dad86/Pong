#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <functional>

class Padel;
typedef void(Padel::* ScoreChanger)();
enum class DirectionBall{ LEFT, RIGHT };
class Ball
{
public:
	Ball();
	~Ball();

	const sf::CircleShape& GetCircleShape() const;
	void Update(const sf::Vector2f& position, const sf::Vector2u& windowSize);
	void Move(const float& elapsed);
	void ChangeBallDirection(const sf::RectangleShape& player1,
		const sf::RectangleShape& player2, const sf::Vector2f& positionPlayer1,
		const sf::Vector2f& positionPlayer2);
	void BounceDirection(const int& boundUp, const int& boundDown);
	void Reset();
	const sf::Vector2f GetPosition() const;
	bool SetPoint(std::function<void()> player1ScoreChanger, std::function<void()> player2ScoreChanger);
	DirectionBall GetBallDirection();

	
private:
	bool _Colision;
	sf::Vector2u _WindowSize;
	sf::CircleShape _ballShape;
	float _radius;
	DirectionBall _direction;
	float _speed;
	float _angle;
};

