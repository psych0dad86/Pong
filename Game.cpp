#include "Game.hpp"

Game::Game()
{


	_paddle_1StartPosition = sf::Vector2f(_window.GetWindowSize().x / 10, _window.GetWindowSize().y / 2);
	_paddle_2StartPosition = sf::Vector2f(_window.GetWindowSize().x / 10 * 9, _window.GetWindowSize().y / 2);

	_player1.SetPosition(_paddle_1StartPosition);

	_player2.SetOriging(sf::Vector2f(50, 100));
	_player2.SetPosition(_paddle_2StartPosition);

	_clock.restart();
	_elapsedTime = 0.0f;
}

Game::~Game()
{
}

void Game::UpDate()
{
	_window.UpDate();

	float timestep = 1.0f / 10;
	if (_elapsedTime >= timestep)
	{
		_player1.Move(_elapsedTime);
		_player2.Move(_elapsedTime);
		_elapsedTime -= timestep;
	}
}

void Game::Rendering()
{
	_window.BeginDraw();
	_window.EndDraw(_player1.GetShapeAdress());
	_window.EndDraw(_player2.GetShapeAdress());
	_window.DisplayWindow();
}
void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_player1.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_player1.SetDirection(Direction::Down);
	}
	else 
	{
		_player1.SetDirection(Direction::None);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_player2.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_player2.SetDirection(Direction::Down);
	}
	else
	{
		_player2.SetDirection(Direction::None);
	}
}
void Game::RestartClock()
{
	_elapsedTime = _clock.restart().asMilliseconds();
	
}
sf::RenderWindow& Game::GetWindow()
{
	return _window.GetWindow();
}
