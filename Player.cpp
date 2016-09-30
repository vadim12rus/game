#include "stdafx.h"
#include "Player.h"

void InitializePlayer(Player & player, TextureGame & texture)
{
	player.playerSprite.setTexture(texture.playerTexture);
	player.playerSprite.setTextureRect(sf::IntRect(150, 121, 150, 121));
	player.playerSprite.setPosition(250, 250);
}

void handlePlayerKeyPress(const sf::Event::KeyEvent &event, Player &player)
{
	bool handled = true;
	switch (event.code)
	{
	case sf::Keyboard::Up:
		player.direction = Direction::UP;
		break;
	case sf::Keyboard::Down:
		player.direction = Direction::DOWN;
		break;
	case sf::Keyboard::Left:
		player.direction = Direction::LEFT;
		break;
	case sf::Keyboard::Right:
		player.direction = Direction::RIGHT;
		break;
	default:
		handled = false;
		break;
	}
}

void handlePlayerKeyRelease(const sf::Event::KeyEvent &event, Player &player)
{
	bool handled = true;
	switch (event.code)
	{
	case sf::Keyboard::Up:
		if (player.direction == Direction::UP)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Down:
		if (player.direction == Direction::DOWN)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Left:
		if (player.direction == Direction::LEFT)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Right:
		if (player.direction == Direction::RIGHT)
		{
			player.direction = Direction::NONE;
		}
		break;
	default:
		handled = false;
		break;
	}
}