#pragma once
#include"pch.h"
#include"State.h"
#include"UIElement.h"

class Menu : public State
{
public:
    void init(const sf::Vector2f& viewport);
	void cleanup();

	void handleEvent(sf::Event& ev);
	void update(float dt);
	void draw(sf::RenderTarget& target);
	void resizeCallback(const sf::Vector2f& viewport);

	
protected:
    virtual ~Menu() {};
	void addElement(UIElement* element);

private:
	bool pressed = false;
	float space = 0.05f;
	std::vector<UIElement*> elements;
	
	sf::Vector2f cursor;
	sf::Vector2f viewport;
	sf::Vector2f size {0.f,0.f};

	static sf::Font font;
	static bool fontLoaded;
};