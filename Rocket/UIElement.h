#pragma once
#include "pch.h"

class UIElement
{
public:
    const sf::Vector2f &getSize() { return size; }
    virtual void setFont(sf::Font& font) = 0;
    virtual bool update(sf::Vector2f cursor, bool isPressed, bool reset) = 0;
    virtual void draw(sf::RenderTarget &target, sf::Vector2f viewport, sf::Vector2f pos) = 0;

protected:
    sf::Vector2f scale;
    sf::Vector2f size;
    bool pressed = false;
};
