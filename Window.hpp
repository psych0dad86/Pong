#pragma once
#include "padel.hpp"




class Window : sf::RenderWindow
{
public:
	Window();
	~Window();


	void BeginDraw();




	void DisplayWindow();
	void UpDate();
	inline sf::RenderWindow& GetWindow() { return _window; }

	const sf::Vector2u GetWindowSize()const;
	

	template<typename T>
	inline void EndDraw(const T& drawable)
	{
		_window.draw(drawable);
	};

private:
	void SetUp(const std::string& title);
	void Create();
	void Close();

	sf::RenderWindow _window;
	std::string _windowTitle;
	sf::Vector2u _windowSize;

	bool _isFullscreen;
};




