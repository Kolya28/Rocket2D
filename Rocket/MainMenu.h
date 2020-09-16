#pragma once
#include "pch.h"
#include "Menu.h"
#include "UIButton.h"

class MainMenu : public Menu
{
public:
    MainMenu()
    {
        addElement(new UIButton("button", [&]() { std::cout << "pressed1\n"; }));
        addElement(new UIButton("button", [&]() { std::cout << "pressed2\n"; }));
        addElement(new UIButton("button", [&]() { std::cout << "pressed3\n"; }));
        addElement(new UIButton("button", [&]() { std::cout << "pressed4\n"; }));
    }
};