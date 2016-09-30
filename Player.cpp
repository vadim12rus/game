#include "stdafx.h"
#include "Player.h"
#include "Config.h"
#include <iostream>

void InitializePlayer(Player & player, TextureGame & texture)
{
	player.playerSprite.setTexture(texture.playerTexture);
	player.playerSprite.setTextureRect(sf::IntRect(150, 121, 150, 121));
	player.playerSprite.setPosition(250, 250);
	player.direction = Direction::NONE;
	player.countFrame = 0;
	player.currentFrame = 0;
	player.isShoot = false;
}

void UpdateMousePosition(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	mousePosition = window.mapPixelToCoords(pixelPos);
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


void UpdatePlayerFrame(Player &player, float const step, sf::Vector2f &intRect) //обновление кадров
{
	player.currentFrame += step;
	if (player.currentFrame > player.countFrame)
	{
		player.currentFrame -= player.countFrame;
	}
	player.playerSprite.setTextureRect(sf::IntRect(intRect.x, intRect.y * int(player.currentFrame), 150, 122));
}



void UpdatePlayer(Player &player, float elapsedTime)
{
	const float step = PLAYER_SPEED * elapsedTime;
	UpdatePlayerRotation(player);

	sf::Vector2f speed(0, 0);
	sf::Vector2f intRect(0, 122);
	if (player.isShoot)
	{
		intRect = sf::Vector2f(450, 122);
	}
	switch (player.direction)
	{
	case Direction::UP:
		player.countFrame = 16;
	break;
	case Direction::DOWN:
		player.countFrame = 16;
	break;
	case Direction::LEFT:
		player.countFrame = 16;
	break;
	case Direction::RIGHT:
		player.countFrame = 16;
	break;
	case Direction::NONE:
		if (player.isShoot)
		{
			intRect = sf::Vector2f(300, 122);
		}
		else
		{
			intRect = sf::Vector2f(150, 122);
		}
		player.countFrame = 20;
		
	break;
	}
	std::cout << player.isShoot << std::endl;
	UpdatePlayerFrame(player, step, intRect);
	//player.playerSprite.move(0.1f * step, 0.1f * step);
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
	case sf::Keyboard::W:
		if (player.direction == Direction::UP)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::S:
		if (player.direction == Direction::DOWN)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::A:
		if (player.direction == Direction::LEFT)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::D:
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