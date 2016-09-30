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
	float windowWidth = static_cast<float>(window.getSize().x);
	float windowHeight = static_cast<float>(window.getSize().y);
	window.setView(sf::View(sf::FloatRect(0, 0, windowWidth, windowHeight)));
}