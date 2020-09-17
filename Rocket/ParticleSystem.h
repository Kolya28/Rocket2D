#include "pch.h"

class ParticleSystem
{
public:
    void create()
    {
        particles.resize(maxCount);

        for (auto &p : particles)
        {
            p = createParticle();
        }
    }

    void draw(sf::RenderTarget &target, sf::Vector2f viewport, sf::Vector2f pos)
    {
        for (auto &p : particles)
        {
            sf::CircleShape circle;
            circle.setPosition(p.pos + pos);
            circle.setRadius(15.f);
            circle.setOrigin(circle.getRadius() / 2.f, circle.getRadius() / 2.f);
            circle.setFillColor(p.color);
            //std::cout << p.pos.x << ' ' << p.pos.y << '\n';
            target.draw(circle);
        }
    }

    void update(float dt, float length = 1.f)
    {
        for (auto &p : particles)
        {
            if (static_cast<float>(p.color.a) - p.burnSpeed * dt < 0.f)
            {
                p = createParticle(length);
                continue;
            }

            p.color.a -= p.burnSpeed * dt;
            p.pos += p.V * dt;
        }
    }

private:
    struct Particle
    {
        sf::Vector2f pos;
        sf::Vector2f V;
        float burnSpeed;
        sf::Color color;
    };

    std::mt19937 random_engine = std::mt19937(std::random_device()());

    Particle createParticle(float length = 1.f)
    {
        length *= maxLength;
        Particle p;

        static std::uniform_real_distribution<> dist_lifetime(length*0.8f, length);
        static std::uniform_real_distribution<> dist_Vx(-300.f, 300.f);
        static std::uniform_real_distribution<> dist_Y(-20.f, 20.f);
        static std::uniform_real_distribution<> dist_X(-20.f, 20.f);

        p.color = sf::Color(255,255,0,200);
        p.burnSpeed = p.color.a / dist_lifetime(random_engine);
        p.pos = {dist_X(random_engine), dist_Y(random_engine)};

        p.V = {dist_Vx(random_engine), 2000.f};

        return p;
    }

    const float maxLength = 0.3f;

    std::vector<Particle> particles;
    int maxCount = 50;
};