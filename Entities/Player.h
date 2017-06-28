#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Time.h"

class Player : public Entity
{
    public:
        Player();
        virtual ~Player();

        void    Update      () override;

        void    OnMouseDown () override;

    private:
        float moveSpeed = 0.005f;
};
