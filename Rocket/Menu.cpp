#include "Menu.h"

bool Menu::fontLoaded = false;
sf::Font Menu::font;

void Menu::init(const sf::Vector2f &viewport)
{
    size.y -= space;
    resizeCallback(viewport);

    if(!fontLoaded)
    {
        fontLoaded = true;
        if(!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
            throw std::runtime_error("Font Atial.ttf load error");
    }

    for(auto& el : elements)
        el->setFont(font);
}

void Menu::cleanup()
{
    for(auto& el : elements)
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
        }
        break;
    }
}

void Menu::update(float dt)
{
    sf::Vector2f center = viewport / 2.f;
    sf::Vector2f curr = {center.x, viewport.y * (1.f - size.y) / 2.f};

    for (auto &el : elements)
    {
        curr.x = viewport.x * (1.f - el->getSize().x) / 2.f;

        el->update({(cursor.x - curr.x) / (el->getSize().x * viewport.x),
                    (cursor.y - curr.y) / (el->getSize().y * viewport.y)},
                   pressed);

        curr.y += (el->getSize().y + space) * viewport.y;
    }
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