#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

struct Game
{
	sf::RenderWindow window;
	Player player;
	TextureGame textureGame;
};

void InitializeGame(Game & game);