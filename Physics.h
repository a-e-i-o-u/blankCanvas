#pragma once

#include <SFML/Graphics.hpp>

class Level;

struct Physics
{
    public:

        static bool checkPosition(sf::Vector2i   checkPosition);
        static bool checkPosition(int checkPosX, int checkPosY);

        static Level* level;
};
