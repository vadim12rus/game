#include "stdafx.h"
#include "Game.h"

void InitializeGame(Game & game)
{
	game.window.create(sf::VideoMode(800, 600), "Window Title");
	game.textureGame.LoadingFromFileTexture();
	InitializePlayer(game.player, game.textureGame);
	InitializePlayer(game.player, game.textureGame);
}
