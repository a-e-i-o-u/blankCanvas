#pragma once

#include <SFML/Graphics.hpp>    /// SFML API
#include <new>                  /// std::nothrow

#include "Time.h"
#include "Input.h"
#include "Physics.h"

#include "Entities/Entity.h"

const unsigned int  maxEntities = 256;

struct Level
{
    public:
        Level();
        virtual ~Level();

        Entity*     entities[maxEntities];

        Entity*     createEntity    (Entity* newEntity);
        Entity*     createEntity    (Entity* newEntity, sf::Vector2i checkPosition);

        void        deleteEntity    (Entity* targetEntity);
        void        deleteEntity    (int targetID);

        void        Update          ();
        void        Draw            (sf::RenderWindow& window);

        Entity*  FindEntity      (std::string searchTag);

        void CleanUp();
};
