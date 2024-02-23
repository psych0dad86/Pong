#include "Window.hpp"

Window::Window()
{


	SetUp("Pong V.0.0");
}

Window::~Window()
{
}

void Window::SetUp(const std::string& title)
{
	_isFullscreen = true;
	_windowTitle = title;
	sf::VideoMode desktopSize = sf::VideoMode::getDesktopMode();
	_windowSize.x = desktopSize.width;
	_windowSize.y = desktopSize.height;
	Create();
	
}

void Window::Create()
{
	
	auto style = _isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
	_window.create(sf::VideoMode(_windowSize.x, _windowSize.y, 32), _windowTitle, style);
	_isFullscreen = !_isFullscreen;
}

void Window::Close()
{
	_window.close();
}

void Window::BeginDraw()
{
	_window.clear(sf::Color::Magenta);
}


void Window::DisplayWindow()
{
	_window.display();
}

void Window::UpDate()
{
	sf::Event event;

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		{
			_window.close();
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			_window.close();
			this->Create();
		}
	}
	_window.setFramerateLimit(60);
}

const sf::Vector2u Window::GetWindowSize() const
{
	return _windowSize;
}
