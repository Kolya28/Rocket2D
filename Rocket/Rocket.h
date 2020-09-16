#include "pch.h"

class Rocket
{
public:
    void update(float dt);
    void draw(sf::RenderTarget &target);
    const sf::Vector2f &getPos() { return pos; }

private:
    sf::Vector2f pos{0,0};
};