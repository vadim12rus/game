#pragma once
#include <SFML/Graphics.hpp>

struct TextureGame
{
	sf::Texture playerTexture;
	sf::Texture cursorTexture;

	void LoadingFromFileTexture();
};