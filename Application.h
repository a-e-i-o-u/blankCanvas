#pragma once

#include <new>                  /// std::nothrow
#include <string>               /// std::string
#include <stdio.h>              /// printf()
#include <iostream>             /// std::cout

#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Input.h"
#include "Level.h"
#include "Time.h"

#include "ResourceManagers/TextureManager.h"

class App
{
    public:

        void Run ();

    private:

        void    Update  ();
        void    Draw    ();

        void    StartUp         ();     /// Called at the start of the Run() Function.
        void    CleanUp         ();     /// Called at the end of the Run() Function.
        void    pollEvents      ();     /// Called every time at the saw of the Main Loop.
        float   calculateTime   ();     /// Calculate deltaTime.


    private:

        Level*      level;

        bool        isFocused = true;

    private:

        TextureManager      textureManager;

        sf::Clock           clock;
        sf::RenderWindow    window;
        sf::View            view;
};
