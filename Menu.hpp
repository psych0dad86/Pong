#pragma once
#include "CustomFont.hpp"

enum class Button{BUTTON_1, BUTTON_2, BUTTON_3};
class Menu : public sf::Drawable
{
public:
	Menu();
	~Menu();


	void Update(const sf::Vector2u windowsize);
	void SetUpbuttonPos(const sf::Vector2u windowsize);
	void SetSelectedButton(const sf::Keyboard::Key& button);
	void SetSelectedButton(const Button& button);
	void changeTextFirstSecondButton(const std::string& text, const std::string& text2);
	const Button getSelectedButton() const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	

private:
	sf::Vector2f _buttonSize;
	sf::Vector2f _backGrondSize;
	sf::Vector2f _buttonPos;
	sf::Vector2f _PositionBackground;
	sf::RectangleShape _shape[4];
	CustomFont _menuFont[4];
	Button _selectedButton;
	unsigned int _CharSize;
};

