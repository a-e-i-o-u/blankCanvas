#pragma once

#include <map>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class TextureManager
{
    public:

        /// Get Texture* Function
        sf::Texture*    get_image           ( const std::string  filename   );

        /// Delete Texture* Function
        void            delete_image        ( const sf::Texture* texture    );
        void	        delete_image        ( const std::string  filename   );

        void            deleteEverything    ();

    private:
        std::map    < std::string, sf::Texture* >  textures;
};
