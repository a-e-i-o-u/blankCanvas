#include "Level.h"

Level::Level()
{
    for(unsigned int i = 0; i < maxEntities; i++) {
        entities[i] = nullptr;
    }
    Entity::level  = this;
    Physics::level = this;
}
Level::~Level() { }

Entity* Level::createEntity(Entity* newEntity)
{
    bool succesfullyCreated = false;
    int  targetID           = 0;


    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i] == NULL) {
            entities[i] = newEntity;
            succesfullyCreated = true;
            targetID = i;
            break;
        }
    }

    if(succesfullyCreated) {
        newEntity -> level      = this;
        newEntity -> uniqueID   = targetID;
        newEntity -> Awake  ();
        newEntity -> Start  ();
        return newEntity;
    } else {
        delete newEntity;
        return NULL;
    }
}

Entity* Level::createEntity(Entity* newEntity, sf::Vector2i checkPosition)
{
    bool succesfullyCreated = false;

    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i] == NULL) {
            entities[i] = newEntity;
            succesfullyCreated = true;
            break;
        }
    }

    if(succesfullyCreated) {
        newEntity -> level = this;
        newEntity -> setPosition(checkPosition);
        newEntity -> Awake();
        newEntity -> Start();
        return newEntity;
    } else {
        delete newEntity;
        return NULL;
    }
}

void Level::deleteEntity(Entity* targetEntity)
{
    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i]) {
            if(entities[i] == targetEntity) {
                delete entities[i];
                entities[i] = nullptr;
                break;
            }
        }
    }
}

void Level::deleteEntity(int targetID)
{
    if(entities[targetID] != NULL) {
        delete entities[targetID];
        entities[targetID] = nullptr;
    }
}



void Level::Update()
{
    /// Checking Entity Positions for OnMouseDown() and OnMouseOver() functions.
    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i]) {
            if(entities[i] -> getPosition() == Input::mousePosition) {
                entities[i] -> OnMouseOver();

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    entities[i] -> OnMouseDown();
            }
        }
    }

    /// Calling Update()
    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i]) {
            entities[i] -> Update();
        }
    }

    /// Calling LateUpdate()
    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i]) {
            entities[i] -> LateUpdate();
        }
    }
}

void Level::Draw(sf::RenderWindow& window)
{
    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i]) {
            if(entities[i] -> drawBody)
                entities[i] -> Draw(window);
        }
    }
}

void Level::CleanUp()
{
    delete[] entities;

}

Entity* Level::FindEntity(std::string searchTag)
{
    for(unsigned int i = 0; i < maxEntities; i++) {
        if(entities[i] -> tag  == searchTag) {
            return entities[i];
        }
    }
    return NULL;
}
