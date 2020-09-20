#include "pch.h"
#include "ParticleSystem.h"

class Rocket
{
public:
    void create();
    void update(float dt);
    void draw(sf::RenderTarget &target);
    const sf::Vector2f &getPos() { return pos; }

private:
    ParticleSystem particleSystem;

    sf::Vector2f pos{0, 0};
    float h = 0.f;
    float m = 15'000.f;
    long double G = 6.67408L * std::pow(10.L, -11);
    long double M = 5.9726L * std::pow(10.L, 24);
    float GM = static_cast<float>(G * M);
    float r = 6'371'000.f;
    float fuel_m = 10.f;
    float burn_q = 43'000'000.f;
    float burn_n = 0.5f;
    float burn_speed = 1.f;
    float burn_max = 1.f;
    float Vy = 0.f;
};