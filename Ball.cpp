#include "Ball.hpp"

Ball::Ball() : _radius(25), _speed(0.2f)
{
	_ballShape.setFillColor(sf::Color::Green);
	_ballShape.setRadius(_radius);
	_ballShape.setOutlineThickness(3);
	_ballShape.setOutlineColor(sf::Color::Black);
	_direction = DirectionBall::LEFT;
	_angle = -135;
	_Colision = false;
	Update(sf::Vector2f(0,0), sf::Vector2u(600, 800));

}

Ball::~Ball()
{
}

const sf::CircleShape& Ball::GetCircleShape() const
{
	return _ballShape;
}

void Ball::Update(const sf::Vector2f& position, const sf::Vector2u& windowSize)
{
	_WindowSize = windowSize;
	_ballShape.setOrigin(_radius, _radius);
	_ballShape.setPosition(position);

}

void Ball::Move(const float& elapsed)
{
	float angleRad = _angle / 180.0f * 3.14159f;
	float velX = _speed * std::cos(angleRad);
	
	float velY = _speed * std::sin(angleRad);
			_ballShape.setPosition(sf::Vector2f(_ballShape.getPosition().x + (velX * elapsed),
			_ballShape.getPosition().y + (velY * elapsed)));

}

void Ball::ChangeBallDirection(const sf::RectangleShape& player1,
	const sf::RectangleShape& player2, const sf::Vector2f& positionPlayer1,
	const sf::Vector2f& positionPlayer2)
{
	sf::FloatRect circleBounds = _ballShape.getGlobalBounds();
	sf::FloatRect player1Bounds = player1.getGlobalBounds();
	sf::FloatRect player2Bounds = player2.getGlobalBounds();

	BounceDirection(0, _WindowSize.y);

	if (circleBounds.intersects(player1Bounds))
	{
		if (_Colision == false)
		{
			if (_ballShape.getPosition().y  < positionPlayer1.y + 125 && _ballShape.getPosition().y  > positionPlayer1.y - 125 && _ballShape.getPosition().x > player1.getPosition().x + 50)
			{
				_angle = _angle / 3;
				_speed += 0.05f;
				_direction = DirectionBall::RIGHT;

			}

			_Colision = true;
		}
	
	}
	else if (circleBounds.intersects(player2Bounds))
	{
		if (_Colision == false)
		{
			if (_ballShape.getPosition().y  < positionPlayer2.y + 125 &&_ballShape.getPosition().y  > positionPlayer2.y - 125 && _ballShape.getPosition().x < player2.getPosition().x )
			{
				_angle = _angle * 3;
				_speed += 0.05f;
				_direction = DirectionBall::LEFT;
			}
			_Colision = true;
		}
	}
	
}

void Ball::BounceDirection(const int& boundUp, const int& boundDown)
{
	if (_direction == DirectionBall::RIGHT)
	{
		if (_ballShape.getPosition().y <= boundUp + _radius)
		{
			_angle = 45;
			_Colision = false;
		}
		if (_ballShape.getPosition().y >= boundDown - _radius)
		{
			_angle = -45;
			_Colision = false;
		}
		
	}
	else if (_direction == DirectionBall::LEFT)
	{
		if (_ballShape.getPosition().y <= boundUp + _radius)
		{
			_angle = 135;
			_Colision = false;
		}
		if (_ballShape.getPosition().y >= boundDown - _radius)
		{
			_angle = -135;
			_Colision = false;
		}
		
	}
	else
	{
		std::cout << "Error Ball has no Direction" << std::endl;
	}
}

void Ball::Reset()
{
	_speed = 0.2f;
	if (_direction == DirectionBall::RIGHT)
	{
		_angle = _angle * 3;
		_direction = DirectionBall::LEFT;
	}
	else if (_direction == DirectionBall::LEFT)
	{
		_angle = _angle / 3;
		_direction = DirectionBall::RIGHT;
	}
	_ballShape.setPosition(sf::Vector2f(_WindowSize.x/2 ,_WindowSize.y/2 ));

	_Colision = false;
}

const sf::Vector2f Ball::GetPosition()const
{
	return _ballShape.getPosition();
}



bool Ball::SetPoint(std::function<void()> player1ScoreChanger, std::function<void()> player2ScoreChanger)
{
	if (_ballShape.getPosition().x <= 0)
	{
		player1ScoreChanger();
		this->Reset();
		return true;
	}
	else if (_ballShape.getPosition().x >= _WindowSize.x)
	{
		player2ScoreChanger();
		this->Reset();
		return true;
	}
	return false;
}




