#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Config.h"

void Update(Game &game, float elapsedTime)
{
	UpdateMousePosition(game.window, game.player.mousePosition);
	UpdatePlayer(game.player, elapsedTime);
}

void HandleEvents(sf::RenderWindow & window, Player &player)
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
		case sf::Event::KeyPressed:
			HandlePlayerKeyPress(event.key, player);
			break;
		case sf::Event::KeyReleased:
			HandlePlayerKeyRelease(event.key, player);
		default:
			break;
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				player.isShoot = true;
			}
		}
		else  if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				player.isShoot = false;
			}
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
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (game.window.isOpen())
	{
		timeSinceLastUpdate += game.clock.restart();
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			float elapsedTime = timeSinceLastUpdate.asSeconds();
		    HandleEvents(game.window, game.player);
		    Update(game, elapsedTime);
		    Render(game.window, game.player.playerSprite);
		    timeSinceLastUpdate -= TIME_PER_FRAME;
		}
	}

	return 0;
}