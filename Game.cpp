#include "Game.hpp"

Game::Game() 
{
	
	
	_paddle_1StartPosition = sf::Vector2f(_window.GetWindowSize().x / 10, _window.GetWindowSize().y / 2);
	_paddle_2StartPosition = sf::Vector2f(_window.GetWindowSize().x / 10 * 9, _window.GetWindowSize().y / 2);

	_player1.SetPosition(_paddle_1StartPosition);

	_player2.SetOriging(sf::Vector2f(50, 100));
	_player2.SetPosition(_paddle_2StartPosition);



	_menuOpen = true;
	_clock.restart();
	_elapsedTime = 0.0f;
}

Game::~Game()
{
}

void Game::UpDate()
{
	_window.UpDate();
	_menu.Update(_window.GetWindowSize());

	float timestep = 16.5f;
	if(_elapsedTime >= timestep)
	{
		_player1.Move(_elapsedTime,_window.GetWindowSize());
		_player2.Move(_elapsedTime,_window.GetWindowSize());
		_elapsedTime -= timestep;
	}
}

void Game::Rendering()
{
	_window.BeginDraw();

	if (_menuOpen == false)
	{
		_window.EndDraw(_player1.GetShapeAdress());
		_window.EndDraw(_player2.GetShapeAdress());

	}
	else
	{

		_window.EndDraw(_menu);
	}
	
	
	_window.DisplayWindow();
}
void Game::HandleInput()
{
	if (_menuOpen == false)
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

	static bool keyWasReleased = true;;
	static sf::Clock keyClock;
	if (keyWasReleased == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			_menuOpen = !_menuOpen;
			keyWasReleased = false;
		}

		if (_menuOpen == true)
		{
			if (keyClock.getElapsedTime().asSeconds() >= 0.1f)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					_menu.SetSelectedButton(sf::Keyboard::Up);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					_menu.SetSelectedButton(sf::Keyboard::Down);
				}
				keyClock.restart();
			}
			
		}
		
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		keyWasReleased = true;
	}



}
void Game::RestartClock()
{
	_elapsedTime += _clock.restart().asMilliseconds();
	
}
sf::RenderWindow& Game::GetWindow()
{
	return _window.GetWindow();
}
