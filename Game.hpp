#pragma once
#include "Padel.hpp"
class Game
{
public:
	Game();
	~Game();

	void UpDate();
	void Rendering();

	void HandleInput();
	void RestartClock();

	sf::RenderWindow& GetWindow();

private:
	Padel _player1;
	Padel _player2;
	Window _window;
	sf::Clock _clock;
	float _elapsedTime;
	
	sf::Vector2f _paddle_1StartPosition;
	sf::Vector2f _paddle_2StartPosition;
	


};
