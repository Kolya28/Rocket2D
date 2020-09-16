#include"Rocket.h"


void Rocket::update(float dt) 
{
    pos.y -= dt * 10.f;
}

void Rocket::draw(sf::RenderTarget &target) 
{
    sf::RectangleShape shape;
    shape.setSize({100.f,100.f});
    shape.setOrigin(shape.getGlobalBounds().width/2.f, shape.getGlobalBounds().height);
    shape.setPosition(pos);
    target.draw(shape);
}
