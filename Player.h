#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"

struct Player
{
	sf::Sprite playerSprite;
};

void InitializePlayer(Player & player, TextureGame & texture);
