#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <string>
#include <memory>
#include <thread>


class LabelController
{
public:
	LabelController(const sf::Font &font, unsigned int fontSize, sf::Color color, const std::string &text, sf::Vector2f pos);
	void setText(const std::string &text);
	std::string getText() const;

	void toCenterX(float windowWidth);
	void toCenterY(float windowHeight);
	void toBottomY(float windowHeight);
	void setPosition(const sf::Vector2f &pos);
	sf::Vector2f getPosition() const;
	void move(const sf::Vector2f &pos);
	
	void blink(bool blinkState, float delay = 0.f);

	virtual void draw(sf::RenderWindow &window);

protected:
	sf::Text textObj;

	bool isVisible = true;
	bool isBlinking = false;
	float blinkDelay = 0.f;
	sf::Clock blinkingClock;
};