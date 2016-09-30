#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"


void handleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void render(sf::RenderWindow & window, sf::Sprite & playerSprite)
{
	window.clear();
	window.draw(playerSprite);
	window.display();
}

int main(int, char *[])
{
	Game game;
	InitializeGame(game);
	while (game.window.isOpen())
	{
		handleEvents(game.window);
		render(game.window, game.player.playerSprite);
	}

	return 0;
}