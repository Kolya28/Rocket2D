#pragma once
#include "pch.h"
#include "UIElement.h"

class UISlider : public UIElement
{
public:
    UISlider(const std::string &name, float value = 0.5f, sf::Vector2f distribution = {0.f, 1.f})
    {
        if (name.empty())
            textSize = {0.f, 0.f};
        else
            textSize = {0.f, 0.07f};

        sliderSize = {0.8f, 0.05f};
        size = textSize + sliderSize;

        this->name = name;
        this->value = default_value = value;
        this->distribution = distribution;
    }

    void setFont(sf::Font &font)
    {
        text.setFont(font);
    }

    bool update(sf::Vector2f cursor, bool isPressed, bool reset)
    {
        if (pressed || sf::FloatRect(-100.f, 0.f, 200.f, 1.f + 0.1f).contains(cursor))
        {
            if (reset)
            {
                value = default_value;
                return false;
            }

            if (isPressed)
            {
                value = cursor.x;

                if (value < 0.f)
                    value = 0.f;

                if (value > 1.f)
                    value = 1.f;

                pressed = true;
            }
            else
                pressed = false;
        }
        else if (!isPressed)
            pressed = false;

        return pressed;
    }

    void draw(sf::RenderTarget &target, sf::Vector2f viewport, sf::Vector2f pos)
    {
        float safezone = std::min(viewport.x, viewport.y);
        sf::Vector2f sSize(sliderSize * safezone);
        sf::Vector2f tSize(textSize * safezone);

        sf::RectangleShape shape;
        shape.setOutlineColor(sf::Color::Yellow);
        shape.setOutlineThickness(std::min(viewport.x, viewport.y) / 250.f);

        shape.setFillColor(sf::Color(200, 200, 200));

        shape.setSize(sSize);
        shape.setPosition(pos);
        shape.move(-shape.getSize().x / 2.f, tSize.y);

        target.draw(shape);

        //slider

        float begin = pos.x - sSize.x / 2.f;
        float end = pos.x + sSize.x / 2.f - sSize.y;
        float posX = (end - begin) * value + begin;

        shape.setSize({sSize.y, sSize.y});
        shape.setPosition(posX, pos.y + tSize.y);

        shape.setOutlineThickness(0.f);
        shape.setFillColor(sf::Color::Red);
        target.draw(shape);

        //text
        if (name.empty())
            return;

        std::string str = name + ": " + std::to_string(getValue());

        if (str.size() > 5)
            for (int i = 0; i < 5; ++i)
                str.pop_back();

        text.setString(str);
        text.setCharacterSize(std::min(viewport.x, viewport.y) / 20.f);
        text.setOrigin(text.getGlobalBounds().width / 2.f, text.getGlobalBounds().height / 2.f);
        text.setPosition(pos.x, pos.y + tSize.y / 3.f);
        target.draw(text);
    }

    float getValue() { return distribution.x + (distribution.y - distribution.x) * value; }

private:
    sf::Vector2f lastCursor;
    sf::Vector2f distribution;
    sf::Vector2f textSize, sliderSize;
    std::string name;
    sf::Text text;
    float value, default_value;
};