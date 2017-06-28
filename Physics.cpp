#include "Physics.h"

#include "Level.h"

Level* Physics::level;

bool Physics::checkPosition(sf::Vector2i checkPosition)
{
    if(level) {
        for(unsigned int i = 0; i < maxEntities; i++) {
            if(level -> entities[i]) {
                const bool posXEqual = checkPosition.x == level -> entities[i] -> getPosition().x;
                const bool posYEqual = checkPosition.y == level -> entities[i] -> getPosition().y;
                if(posXEqual && posYEqual && level -> entities[i] -> isSolid)
                    return true;
            }
        }
    }
    return false;
}

bool Physics::checkPosition(int checkPosX, int checkPosY)
{
    if(level) {
        for(unsigned int i = 0; i < maxEntities; i++) {
            if(level -> entities[i]) {
                const bool posXEqual = checkPosX == level -> entities[i] -> getPosition().x;
                const bool posYEqual = checkPosY == level -> entities[i] -> getPosition().y;
                if(posXEqual && posYEqual && level -> entities[i] -> isSolid)
                    return true;
            }
        }
    }
    return false;
}
