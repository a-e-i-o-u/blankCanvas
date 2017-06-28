#include "Entity.h"

#include "../Level.h"

Level* Entity::level;

Entity::Entity()
{
    // Making all entities be 32x32 in size.
    size = sf::Vector2f(32.f, 32.f);
    body.setOrigin(16.f, 16.f);

    tag         = "Default";
    isSolid     = false;
    drawBody    = true;
}

Entity::~Entity()   { }

void Entity::Awake      ()      { }
void Entity::Start      ()      { }
void Entity::Update     ()      { }
void Entity::LateUpdate ()      { }

void Entity::OnMouseDown()      { }
void Entity::OnMouseOver()      { }

void Entity::Draw(sf::RenderWindow& window)
{
    if(drawBody) {
        body.setSize    (size);
        body.setPosition(position.x * 32, position.y * 32);
        body.setRotation(rotation);

        window.draw(body);
    }
}

Entity* Entity::FindEntity(std::string searchTag)
{
    return level -> FindEntity(searchTag);
}
