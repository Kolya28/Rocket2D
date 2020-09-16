#pragma once
#include "pch.h"
#include "UIElement.h"

class UIButton : public UIElement
{
public:
    UIButton(std::string name, std::function<void()> onPressed)
    {
        size = {0.3f, 0.1f};
        this->onPressed = onPressed;
        text.setString(name);
    }

    bool update(sf::Vector2f cursor, bool isPressed, bool reset) override
    {
        if (sf::FloatRect(0.f, 0.f, 1.f, 1.f).contains(cursor))
        {
            if (pressed && !isPressed)
            {
                onPressed();
            }

            pressed = isPressed;
        }
        else
            if(!isPressed)
                pressed = false;

        return pressed;
    }

    void draw(sf::RenderTarget &target, sf::Vector2f viewport, sf::Vector2f pos) override
    {
        sf::RectangleShape shape;
        shape.setOutlineColor(sf::Color::Yellow);
        shape.setOutlineThickness(std::min(viewport.x, viewport.y) / 250.f);

        if (pressed)
            shape.setFillColor(sf::Color(150, 150, 150));
        else
            shape.setFillColor(sf::Color(200, 200, 200));

        shape.setSize({viewport.x * size.x, viewport.y * size.y});
        shape.setPosition(pos);
        shape.move(-shape.getSize().x / 2.f, 0.f);

        target.draw(shape);

        //text

        text.setCharacterSize(std::min(viewport.x, viewport.y) / 15.f);

        text.setOrigin(text.getGlobalBounds().width / 2.f,
                       text.getGlobalBounds().height / 2.f);
        text.setPosition(pos.x, pos.y + (viewport.y * size.y) / 3.f);
        target.draw(text);
    }

    void setFont(sf::Font &font)
    {
        text.setFont(font);
    }

private:
    std::function<void()> onPressed;
    sf::Text text;
};