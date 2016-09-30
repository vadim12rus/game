#include "stdafx.h"
#include "Player.h"
#include "Config.h"
#include <iostream>

void InitializePlayer(Player & player, TextureGame & texture)
{
	player.playerSprite.setTexture(texture.playerTexture);
	player.playerSprite.setTextureRect(sf::IntRect(150, 121, 150, 121));
	player.playerSprite.setPosition(250, 250);
}

void UpdateMousePosition(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	mousePosition = window.mapPixelToCoords(pixelPos);
	//std::cout << mousePosition.x << std::endl;
}

void UpdatePlayerRotation(Player &player) //Поворот игрока за курсором мыши
{
	float dx = player.mousePosition.x - player.playerSprite.getPosition().x;
	float dy = player.mousePosition.y - player.playerSprite.getPosition().y;
	sf::IntRect textureRect = player.playerSprite.getTextureRect();
	player.playerSprite.setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);
	double rotation = (atan2(dy, dx)) * 180 / 3.14159265;
	player.playerSprite.setRotation(static_cast<float>(rotation));
}


void UpdatePlayerFrame(Player &player, float const step)
{
	player.currentFrame += step;
	if (player.currentFrame > 20)
	{
		player.currentFrame -= 20;
	}
	player.playerSprite.setTextureRect(sf::IntRect(150, 122 * int(player.currentFrame), 150, 122));
}

void UpdatePlayer(Player &player, float elapsedTime)
{
	const float step = PLAYER_SPEED * elapsedTime;
	UpdatePlayerRotation(player);
	UpdatePlayerFrame(player, step);
	player.playerSprite.move(0.1f * step, 0.1f * step);

	/*sf::Vector2f position = player.playerSprite.getPosition();
	const float step = PLAYER_SPEED * elapsedTime;
	switch (player.direction)
	{
	case Direction::UP:
	position.y -= step;
	break;
	case Direction::DOWN:
	position.y += step;
	break;
	case Direction::LEFT:
	position.x -= step;
	break;
	case Direction::RIGHT:
	position.x += step;
	break;
	case Direction::NONE:

	break;
	}*/
}

void HandlePlayerKeyPress(const sf::Event::KeyEvent &event, Player &player)
{
	bool handled = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.direction = Direction::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.direction = Direction::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.direction = Direction::RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.direction = Direction::LEFT;
	}
	else
	{
		player.direction = Direction::NONE;
	}
}

void HandlePlayerKeyRelease(const sf::Event::KeyEvent &event, Player &player)
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