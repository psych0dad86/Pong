#pragma once

#include "padel.hpp"

class Window : sf::RenderWindow
{
public:
	Window();
	~Window();


	void BeginDraw();
	void EndDraw(const sf::RectangleShape& drawble);
	void EndDraw(const sf::Text& drawble);
	void EndDraw(const Menu& drawble);
	void EndDraw(const CustomFont& drawble);
	void EndDraw(const sf::CircleShape& drawable);
	void DisplayWindow();
	void UpDate();
	inline sf::RenderWindow& GetWindow() { return _window; }

	const sf::Vector2u GetWindowSize()const;
	


private:
	void SetUp(const std::string& title);
	void Create();
	void Close();

	sf::RenderWindow _window;
	std::string _windowTitle;
	sf::Vector2u _windowSize;

	bool _isFullscreen;
};

