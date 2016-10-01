#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Config.h"

int main(int, char *[])
{
	Game game;
	InitializeGame(game);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	game.window.setMouseCursorVisible(false);
	while (game.window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			float elapsedTime = timeSinceLastUpdate.asSeconds();
		    HandleEvents(game.window, game.player);
		    Update(game, elapsedTime);
		    Render(game.window, game.player.playerSprite, game.cursorSprite);
		    timeSinceLastUpdate -= TIME_PER_FRAME;
		}
	}

	return 0;
}