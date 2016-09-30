#include "stdafx.h"
#include "Game.h"
#include "Config.h"

void InitializeGame(Game & game)
{
	game.window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window Title");
	game.textureGame.LoadingFromFileTexture();
	InitializePlayer(game.player, game.textureGame);
	InitializePlayer(game.player, game.textureGame);
}

void ResizeWindowGame(sf::RenderWindow & window)
{
	unsigned int windowWidth = window.getSize().x;
	unsigned int windowHeight = window.getSize().y;
	window.create(sf::VideoMode(windowWidth, windowHeight), "Game");
}