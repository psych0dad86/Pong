#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Window : sf::RenderWindow
{
public:
	Window();
	~Window();


	void BeginDraw();
	void EndDraw(const sf::RectangleShape& drawble);
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

