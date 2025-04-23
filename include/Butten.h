#pragma once
#include <SFML/Graphics.hpp>

class Butten
{
public:
	Butten(std::string str, sf::Vector2f sizeShape, sf::Vector2f position, sf::Color shapeColor, sf::Color textColor);
	void draw(sf::RenderWindow&);
	bool isClicked();

private:
	sf::RectangleShape m_shape;
	sf::Text m_text;
	std::string m_str;
	sf::Vector2f m_sizeShape;
	sf::Vector2f m_position;
	sf::Color m_shapeColor;
	sf::Color m_textColor;
	sf::Font m_font;

	void centerText();
};