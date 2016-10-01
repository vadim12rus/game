#include "stdafx.h"
#include "Game.h"
#include "Config.h"

void InitializeGame(Game & game)
{
	game.window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window Title");
	game.textureGame.LoadingFromFileTexture();
	game.player.playerSound.LoadingFromFileSound();
	InitializePlayer(game.player, game.textureGame);
	InitializePlayer(game.player, game.textureGame);
	ReplaceStandardCursor(game.textureGame.cursorTexture, game.cursorSprite);
}

void ResizeWindowGame(sf::RenderWindow & window)
{
	float windowWidth = static_cast<float>(window.getSize().x);
	float windowHeight = static_cast<float>(window.getSize().y);
	window.setView(sf::View(sf::FloatRect(0, 0, windowWidth, windowHeight)));
}

void UpdateCursorPosition(sf::RenderWindow & window, sf::Sprite &cursorSprite)
{
	cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

void ReplaceStandardCursor(sf::Texture &cursorTexture, sf::Sprite &cursorSprite)
{
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setOrigin(cursorTexture.getSize().x / 2.f, cursorTexture.getSize().y / 2.f);
	cursorSprite.setPosition(100, 100);
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
				player.isShot = true;
			}
		}
		else  if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				player.isShot = false;
			}
		}

	}
}

void Update(Game &game, float elapsedTime)
{
	UpdateMousePosition(game.window, game.player.mousePosition);
	UpdatePlayer(game.player, elapsedTime);
	UpdateCursorPosition(game.window, game.cursorSprite);
}


void Render(sf::RenderWindow & window, sf::Sprite & playerSprite, sf::Sprite &cursorSprite)
{
	window.clear();
	window.draw(cursorSprite);
	window.draw(playerSprite);
	window.display();
}