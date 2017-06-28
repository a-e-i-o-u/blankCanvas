#include "Player.h"

Player::Player()
{
    tag = "Player";
}
Player::~Player()   { }


void Player::Update()
{

    if(moveSpeed <= 0) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !Physics::checkPosition(sf::Vector2i(position.x, position.y -1))) {
            position.y--;
            moveSpeed = 0.25f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !Physics::checkPosition(sf::Vector2i(position.x, position.y +1))) {
            position.y++;
            moveSpeed = 0.25f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !Physics::checkPosition(sf::Vector2i(position.x -1, position.y))) {
            position.x--;
            moveSpeed = 0.25f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !Physics::checkPosition(sf::Vector2i(position.x +1, position.y))) {
            position.x++;
            moveSpeed = 0.25f;
        }
    } else {
        moveSpeed -= Time::deltaTime;
    }
}

void Player::OnMouseDown()
{
    printf("Player - OnMouseDown()\n");
}
