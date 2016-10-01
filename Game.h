#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

struct Game
{
	sf::RenderWindow window;
	Player player;
	TextureGame textureGame;

	sf::Sprite cursorSprite;
};

void InitializeGame(Game & game);
void ResizeWindowGame(sf::RenderWindow & window);
void ReplaceStandardCursor(sf::Texture &cursorTexture, sf::Sprite &cursorSprite);
void UpdateCursorPosition(sf::RenderWindow & window, sf::Sprite &cursorSprite);