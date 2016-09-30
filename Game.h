#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

struct Game
{
	sf::RenderWindow window;
	sf::Clock clock;
	Player player;
	TextureGame textureGame;
};

void InitializeGame(Game & game);
void ResizeWindowGame(sf::RenderWindow & window);