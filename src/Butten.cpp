#include "Butten.h"

Butten::Butten(std::string str, sf::Vector2f sizeShape, sf::Vector2f position, sf::Color shapeColor, sf::Color textColor) : m_str(str) ,m_sizeShape(sizeShape), m_position(position), m_shapeColor(shapeColor), m_textColor(textColor)
{
	m_font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
	
	m_shape.setSize(m_sizeShape);
	m_shape.setPosition(m_position);
	m_shape.setFillColor(m_shapeColor);

	m_text.setString(m_str);
	m_text.setFillColor(m_textColor);
	m_text.setCharacterSize(18);
	m_text.setFont(m_font);

	centerText();
}

void Butten::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_text);
}

void Butten::centerText()
{
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	m_text.setPosition(m_position.x + m_sizeShape.x / 2.0f,
		m_position.y + m_sizeShape.y / 2.0f);
}

bool Butten::isClicked(sf::Vector2f& mousePos)
{
	return m_shape.getGlobalBounds().contains(mousePos);
}
