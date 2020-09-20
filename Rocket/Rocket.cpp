#include "Rocket.h"

void Rocket::create()
{
    m += fuel_m;
    particleSystem.create();
}

void Rocket::update(float dt)
{
    particleSystem.update(dt, burn_speed);

    //g=GM/(r+h)^2
    float g = GM / std::pow(r + h, 2);

    float burn = burn_max * burn_speed * dt;
    if(burn > fuel_m)
    {
        burn = fuel_m;
        burn_speed = 0.f;
    }
    
    fuel_m -= burn;
    m -= burn;

    float E = burn * burn_q * burn_n;

    float Fy = 0.f;
    Fy += m * std::sqrt(2.f * E / m / std::pow(dt, 2));
    Fy += -m * g;
    Fy += -Vy/std::abs(Vy+0.000001f) * std::pow(Vy,2);

    float Ay = Fy / m;

    Vy += Ay * dt;

    h += Vy * dt;

    pos.y = -h * 10.f;

    std::cout << Ay << ' ' << Vy << '\n';
}

void Rocket::draw(sf::RenderTarget &target)
{
    if(burn_speed)
        particleSystem.draw(target, {0.f, 0.f}, pos);

    sf::RectangleShape shape;
    shape.setSize({100.f, 100.f});
    shape.setOrigin(shape.getGlobalBounds().width / 2.f, shape.getGlobalBounds().height);
    shape.setPosition(pos);
    target.draw(shape);
}
