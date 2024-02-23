#include "Game.hpp"

int main()
{
	Game game;

	while (game.GetWindow().isOpen())
	{
		game.HandleInput();
		game.UpDate();
		game.Rendering();
		game.RestartClock();
	};
}