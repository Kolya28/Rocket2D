#pragma once
#include "pch.h"
#include "Engine.h"
class Engine;

class State
{
	friend Engine;

protected:
	virtual void init(const sf::Vector2f &viewport) = 0;
	virtual void cleanup() = 0;

	virtual void handleEvent(sf::Event &ev) = 0;
	virtual void update(float dt) = 0;
	virtual void draw(sf::RenderTarget &target) = 0;
	virtual void resizeCallback(const sf::Vector2f &viewport) = 0;
	virtual void pause()
	{
		paused = true;
		visible = false;
	}
	virtual void resume()
	{
		paused = false;
		visible = true;
	}
	inline bool isPaused() { return paused; }
	inline bool isVisible() { return visible; }

	virtual ~State(){};

	static Engine &engine;

	bool paused = false;
	bool visible = true;
};
