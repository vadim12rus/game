#include "stdafx.h"
#include "Game.h"
#include "Config.h"

void InitializeGame(Game & game)
{
	game.window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window Title");
	game.textureGame.LoadingFromFileTexture();
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
	//cursorSprite.setScale(0.2, 0.2);
	cursorSprite.setOrigin(cursorTexture.getSize().x / 2.f, cursorTexture.getSize().y / 2.f);
	cursorSprite.setPosition(100, 100);
}