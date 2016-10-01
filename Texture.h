#pragma once
#include <SFML/Graphics.hpp>

struct TextureGame
{
	sf::Texture playerTexture;
	sf::Texture cursorTexture;
	sf::Texture weaponTexture;

	void LoadingFromFileTexture();
};