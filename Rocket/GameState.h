#pragma once
#include "pch.h"
#include "State.h"
#include "Rocket.h"

class GameState : public State
{
public:
	void init(const sf::Vector2f &viewport);
	void cleanup();

	void handleEvent(sf::Event &ev);
	void update(float dt);
	void draw(sf::RenderTarget &target);
	void resizeCallback(const sf::Vector2f &viewport);

private:
	Rocket rocket;

	sf::Vector2f viewport;
	sf::RectangleShape ground;
	sf::RectangleShape sky_color;
};