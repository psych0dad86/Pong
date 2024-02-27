#include "Game.hpp"

Game::Game() 
{
	
	
	_paddle_1StartPosition = sf::Vector2f(_window.GetWindowSize().x / 10.0f, _window.GetWindowSize().y / 2.0f);
	_paddle_2StartPosition = sf::Vector2f(_window.GetWindowSize().x / 10.0f * 9.0f, _window.GetWindowSize().y / 2.0f);

	_player1.SetPosition(_paddle_1StartPosition);

	_player2.SetOriging(sf::Vector2f(50, 100));
	_player2.SetPosition(_paddle_2StartPosition);

	_scorePlayer1.UpdateName(std::to_string(_player1.GetScore()));
	_scorePlayer2.UpdateName(std::to_string(_player2.GetScore()));

	_scorePlayer1.Update(90, sf::Vector2f(_paddle_1StartPosition.x / 2, _paddle_1StartPosition.y / 4), sf::Color(255, 0, 255));
	_scorePlayer2.Update(90, sf::Vector2f(_window.GetWindowSize().x - _paddle_1StartPosition.x / 2, _paddle_1StartPosition.y / 4), sf::Color(255, 0, 255));

	_ball.Update(sf::Vector2f(_window.GetWindowSize().x / 2.0f, _window.GetWindowSize().y / 2.0f), _window.GetWindowSize());

	_gameRun = false;
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
	if(_elapsedTime >= timestep && _menuOpen == false)
	{
		
		_player1.Move(_elapsedTime,_window.GetWindowSize());
		_player2.Move(_elapsedTime,_window.GetWindowSize());
		_ball.Move(_elapsedTime);
		_ball.ChangeBallDirection(_player1.GetShapeAdress(), _player2.GetShapeAdress(), _player1.GetPosition(),_player2.GetPosition());
		_ball.SetPoint([&](){ _player1.ChangeScore(); }, [&](){_player2.ChangeScore(); });
		_scorePlayer1.UpdateName(std::to_string(_player1.GetScore()));
		_scorePlayer2.UpdateName(std::to_string(_player2.GetScore()));
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
		_window.EndDraw(_scorePlayer1);
		_window.EndDraw(_scorePlayer2);
		_window.EndDraw(_ball.GetCircleShape());

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

	static bool p_WasReleased = true;
	static bool up_wasReleased = true;
	static bool down_wasReleased = true;
	static bool enter_wasReleased = true;
	
	if (p_WasReleased == true)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && _gameRun == true)
		{
			_menuOpen = true;
			p_WasReleased = false;
			//_elapsedTime = 0.0f;
		}

		

		if (_menuOpen == true)
		{
			if (up_wasReleased == true && down_wasReleased == true)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					_menu.SetSelectedButton(sf::Keyboard::Up);
					up_wasReleased = false;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					_menu.SetSelectedButton(sf::Keyboard::Down);
					down_wasReleased = false;
				}
			}
	
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _gameRun == false && enter_wasReleased == true)
			{
				switch (_menu.getSelectedButton())
				{
				case (Button::NEW_GAME):
					//New Game erstellen
					_menuOpen = false;
					_menu.changeTextFirstSecondButton("Continue", "New Game");
					_gameRun = true;
					_elapsedTime = 0.0f;
					
					break;
				case (Button::ONE_VS_ONE):
					
					break;
				case (Button::_EXIT):
					
					_window.Close();
					break;
				default:
					std::cout << "Error, switch case, press Enter menu" << std::endl;
					break;
				}
				enter_wasReleased = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _gameRun == true && enter_wasReleased == true)
			{
				
				switch (_menu.getSelectedButton())
				{
				case (Button::NEW_GAME):
					_menuOpen = !_menuOpen;
					_elapsedTime = 0.0f;
					break;
				case (Button::ONE_VS_ONE):
					//new GAme erstellen
					break;
				case (Button::_EXIT):
					_gameRun = false;
					_menu.changeTextFirstSecondButton("New Game", "1 vs 1");
					_menu.SetSelectedButton(Button::NEW_GAME);
					break;
				default:
					std::cout << "Error, switch case, press Enter pause" << std::endl;
					break;
				}
				enter_wasReleased = false;
			}
		}	


	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		enter_wasReleased = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		p_WasReleased = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		up_wasReleased = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		down_wasReleased = true;
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
