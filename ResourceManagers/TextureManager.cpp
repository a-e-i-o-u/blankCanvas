#include "TextureManager.h"

sf::Texture* TextureManager::get_image(const std::string filename)
{
    // Check, whether the texture already exists
	for( std::map<std::string, sf::Texture*>::const_iterator it = textures.begin();
		 it != textures.end();
		 it++)
	{
		if( filename == it->first ) {
			std::cout << "DEBUG_MESSAGE: " << filename << " using existing texture.\n";
			return it->second;
		}
	}

	// The image doesn't exists. Create it and save it.
	sf::Texture* texture = new sf::Texture();

    // Search project's main directory
	if( texture -> loadFromFile( filename ) ) {
		textures[filename] = texture;
		std::cout << "DEBUG_MESSAGE: " << filename << " loading texture.\n";
		return textures[filename];
	}


	std::cout << "GAME_ERROR: Texture was not found. It is filled with an empty texture.\n";
	delete texture;
	return NULL;
}

void TextureManager::delete_image(const sf::Texture* texture)
{
    for( std::map<std::string, sf::Texture*>::const_iterator it = textures.begin();
		 it != textures.end();
		 it++)
	{
		if( texture == it -> second ) {
			textures.erase( it );
            return;
		}
	}
}

void TextureManager::delete_image(const std::string filename)
{
    std::map<std::string, sf::Texture*>::const_iterator it = textures.find( filename );
	if( it != textures.end() )
        textures.erase( it );
}

void TextureManager::deleteEverything()
{
    for( std::map<std::string, sf::Texture*>::iterator it = textures.begin();
		 it != textures.end();
		 it++)
	{
		delete it -> second;
	}

	textures.clear();
}

