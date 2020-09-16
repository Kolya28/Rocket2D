#pragma once
#include "pch.h"
#include "Menu.h"
#include "UIButton.h"
#include "UISlider.h"
#include "GameState.h"

class MainMenu : public Menu
{
public:
    MainMenu()
    {
        static auto s_fuel = new UISlider("Fuel", 0.5f, sf::Vector2f(0.f, 1000.f));
        static auto s_g = new UISlider("g", 0.5f, sf::Vector2f(0.f, 9.8f * 2.f));

        static auto b_printFuel = new UIButton("Launch", [&]()
        {
            engine.pushState(new GameState);
            pause();
        });


        addElement(s_g);
        addElement(s_fuel);
        addElement(b_printFuel);
    }
};