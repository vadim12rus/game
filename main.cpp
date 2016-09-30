#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"


void HandleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) 
		{
		case sf::Event::Resized:
			ResizeWindowGame(window);
			break;
		case sf::Event::Closed:
			window.close();
			break;
		default:
			break;
		}

	}
}

void Render(sf::RenderWindow & window, sf::Sprite & playerSprite)
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
		HandleEvents(game.window);
		Render(game.window, game.player.playerSprite);
	}

	return 0;
}