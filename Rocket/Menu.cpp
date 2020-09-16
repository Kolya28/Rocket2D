#include "Menu.h"

bool Menu::fontLoaded = false;
sf::Font Menu::font;

void Menu::init(const sf::Vector2f &viewport)
{
    size.y -= space;
    resizeCallback(viewport);

    if (!fontLoaded)
    {
        fontLoaded = true;
        if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
            throw std::runtime_error("Font Atial.ttf load error");
    }

    for (auto &el : elements)
        el->setFont(font);
}

void Menu::cleanup()
{
    for (auto &el : elements)
        delete el;
}

void Menu::handleEvent(sf::Event &ev)
{
    switch (ev.type)
    {
    case sf::Event::MouseMoved:
        cursor = static_cast<sf::Vector2f>(sf::Mouse::getPosition(engine.getWindow()));
        break;

    case sf::Event::MouseButtonPressed:
        switch (ev.key.code)
        {
        case sf::Mouse::Left:
            pressed = true;
            break;
        }
        break;

    case sf::Event::MouseButtonReleased:
        switch (ev.key.code)
        {
        case sf::Mouse::Left:
            pressed = false;
            break;
        case sf::Mouse::Right:
            reset = true;
            break;
        }
        break;
    }
}

void Menu::update(float dt)
{
    sf::Vector2f center = viewport / 2.f;
    sf::Vector2f curr = {center.x, viewport.y * (1.f - size.y) / 2.f};

    for (int i = 0; i < elements.size(); ++i)
    {
        curr.x = viewport.x * (1.f - elements[i]->getSize().x) / 2.f;

        if (focused == -1 || focused == i)
        {
            if (elements[i]->update({(cursor.x - curr.x) / (elements[i]->getSize().x * viewport.x),
                                     (cursor.y - curr.y) / (elements[i]->getSize().y * viewport.y)},
                                    pressed, reset))
                focused = i;
            else
                focused = -1;
        }

        curr.y += (elements[i]->getSize().y + space) * viewport.y;
    }
    reset = false;

    if(focused == -1)
        engine.getWindow().setMouseCursorVisible(true);
    else
        engine.getWindow().setMouseCursorVisible(false);

}

void Menu::draw(sf::RenderTarget &target)
{
    sf::Vector2f center = viewport / 2.f;
    sf::Vector2f curr = {center.x, viewport.y * (1.f - size.y) / 2.f};

    for (auto &el : elements)
    {
        el->draw(target, viewport, curr);
        curr.y += (el->getSize().y + space) * viewport.y;
    }
}

void Menu::resizeCallback(const sf::Vector2f &viewport)
{
    this->viewport = viewport;
}

void Menu::addElement(UIElement *element)
{
    elements.push_back(element);
    size += element->getSize();
    size.y += space;
}