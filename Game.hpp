#pragma once
#include "Window.hpp"
class Game
{
public:
	Game();
	~Game();

	void UpDate();
	void Rendering();

	void HandleInput();
	void RestartClock();
	void ResetGame();
	void StartBreakTime();
	void inputMenu();

	sf::RenderWindow& GetWindow();

private:
	Padel _player1;
	Padel _player2;
	Ball  _ball;

	CustomFont _scorePlayer1;
	CustomFont _scorePlayer2;
	
	Window _window;
	Menu _menu;
	bool _menuOpen;
	bool _gameRun;
	bool _break;
	bool _vsAi;
	sf::Clock _clock;
	sf::Clock _clockBreak;
	float _elapsedTime;
	float _brekTimeinSec;


	
	
	sf::Vector2f _paddle_1StartPosition;
	sf::Vector2f _paddle_2StartPosition;
	


};

