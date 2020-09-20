#include "GameState.h"

void GameState::init(const sf::Vector2f &viewport)
{

    sky_color.setPosition(0.f, 0.f);
    sky_color.setFillColor(sf::Color::Blue);
    ground.setFillColor(sf::Color::Red);

    resizeCallback(viewport);

    rocket.create();
}

void GameState::cleanup()
{
}

void GameState::handleEvent(sf::Event &ev)
{
}

void GameState::update(float dt)
{
    rocket.update(dt);
}

void GameState::draw(sf::RenderTarget &target)
{
    target.draw(sky_color);

    sf::View rocketView = engine.getDefaultView();
    rocketView.setCenter(rocket.getPos());
    target.setView(rocketView);

    target.draw(ground);
    rocket.draw(target);

    target.setView(engine.getDefaultView());
}

void GameState::resizeCallback(const sf::Vector2f &viewport)
{
    this->viewport = viewport;
    ground.setPosition(-viewport.x, 0.f);
    ground.setSize(viewport * 2.f);

    sky_color.setSize(viewport);
}
