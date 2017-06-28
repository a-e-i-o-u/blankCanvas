#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "../Time.h"
#include "../Physics.h"

class Level;

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        virtual void Awake          ();                             /// Called after Object is Created.
        virtual void Start          ();                             /// Called after Start() is called.
        virtual void Update         ();                             /// Called every frame.
        virtual void LateUpdate     ();                             /// Called every frame after Update.
        virtual void Draw           (sf::RenderWindow& window);     /// Called to draw body

        virtual void OnMouseDown    ();                             /// Called when mouse's position is the same as the Entity's and the mouse is pressed.
        virtual void OnMouseOver    ();                             /// Called when mouse's position is the same as the Entity's.

        sf::Vector2i    getPosition() const {return position;}      /// Return position.
        float           getRotation() const {return rotation;}      /// Return rotation.

        ///  Set Functions
        void setPosition    (int newPosX, int newPosY)  {position.x = newPosX; position.y = newPosY; }
        void setPosition    (sf::Vector2i newPosition)  {position   = newPosition;                   }
        void setRotation    (float        newRotation)  {rotation   = newRotation;                   }
        void setTexture     (sf::Texture* newTexture )  {body.setTexture    (newTexture);            }
        void setColor       (sf::Color    newColor   )  {body.setFillColor  (newColor);              }
        void setSize        (sf::Vector2f newSize    )  {size = newSize;    body.setOrigin(size.x /2, size.y/2);}

    public:

        int         uniqueID;       /// UniqueID attributed to every entity.
        bool        drawBody;       /// Boolean to determine if body is drawn or not.
        bool        isSolid;        /// Boolean for collision checking.
        std::string tag;            /// tag, for parsing entities and identifying them.

    protected:

        sf::Vector2f    size;
        sf::Vector2i    position;
        float           rotation;

        sf::RectangleShape  body;

    public:

        static Level*   level;
        static Entity*  FindEntity      (std::string searchTag);
};
