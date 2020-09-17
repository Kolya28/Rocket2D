#include"Rocket.h"


void Rocket::update(float dt) 
{
    float Fy = 0.f;
    float Ay = 0.f;
    //g=GM/(r+h)^2
    float g = GM / std::pow(r + h, 2);
    std::cout << Vy << '\n';

    Fy += m * g;

    Ay += Fy/m;

    Vy -= Ay * dt;

    h += Vy * dt;


    pos.y = -h * 10.f;
}

void Rocket::draw(sf::RenderTarget &target) 
{
    sf::RectangleShape shape;
    shape.setSize({100.f,100.f});
    shape.setOrigin(shape.getGlobalBounds().width/2.f, shape.getGlobalBounds().height);
    shape.setPosition(pos);
    target.draw(shape);
}
