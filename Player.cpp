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

void UpdatePlayerRotation(Player &player) //������� ������ �� �������� ����
{
	float dx = player.mousePosition.x - player.playerSprite.getPosition().x;
	float dy = player.mousePosition.y - player.playerSprite.getPosition().y;
	sf::IntRect textureRect = player.playerSprite.getTextureRect();
	player.playerSprite.setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);
	float rotation = (atan2(dy, dx)) * 180 / 3.14159265f;
	player.playerSprite.setRotation(rotation);
	//std::cout << (atan2(dy, dx)) << std::endl;
}


void UpdatePlayerFrame(Player &player, float const step, sf::Vector2i &intRect) //���������� ������
{
	player.currentFrame += step;
	//std::cout << step << std::endl;
	if (player.currentFrame > player.countFrame)
	{
		player.currentFrame -= player.countFrame;
	}
	player.playerSprite.setTextureRect(sf::IntRect(intRect.x, intRect.y * int(player.currentFrame), 150, 122));
}

/*sf::Vector2f GetNormalVector(Player &player) //��������� � ������� � ������� ������� �������
{
	float dx = player.mousePosition.x - player.playerSprite.getPosition().x;
	float dy = player.mousePosition.y - player.playerSprite.getPosition().y;
	return sf::Vector2f(dx, dy) / hypot(dx, dy);
}*/

void UpdatePlayer(Player &player, float elapsedTime)
{
	const float step = PLAYER_SPEED * elapsedTime;
	UpdatePlayerRotation(player);

	float dx = player.mousePosition.x - player.playerSprite.getPosition().x;
	float dy = player.mousePosition.y - player.playerSprite.getPosition().y;
	float distance = hypot(dx, dy);
	sf::Vector2f normalVector = sf::Vector2f(dx, dy)/ distance;

	sf::Vector2f speed(0, 0);
	sf::Vector2i intRect(0, 122);
	if (distance < 5)
	{
		player.direction = Direction::NONE;
	}
	if (player.isShoot)
	{
		intRect = sf::Vector2i(450, 122);
	}
	switch (player.direction)
	{
	case Direction::UP:
		player.countFrame = 16;
		speed = sf::Vector2f(step * 5 * normalVector.x, step * 5 * normalVector.y);
	break;
	case Direction::DOWN:
		player.countFrame = 16;
		speed = sf::Vector2f(-step * 3 * normalVector.x, -step * 3 * normalVector.y);
	break;
	case Direction::LEFT:
		player.countFrame = 16;
		speed = sf::Vector2f(step * 3 * std::sin(3.14159265 * player.playerSprite.getRotation() / 180.f), -std::cos(3.14159265 * player.playerSprite.getRotation() / 180.f) *step * 3 );
	break;
	case Direction::RIGHT:
		player.countFrame = 16;
		speed = sf::Vector2f(-step * 3 * std::sin(3.14159265 * player.playerSprite.getRotation() / 180.f), std::cos(3.14159265 * player.playerSprite.getRotation() / 180.f) *step * 3);
	break;
	case Direction::NONE:
		if (player.isShoot)
		{
			intRect = sf::Vector2i(300, 122);
		}
		else
		{
			intRect = sf::Vector2i(150, 122);
		}
		player.countFrame = 20;
	break;
	}

	UpdatePlayerFrame(player, step, intRect);
	player.playerSprite.move(speed);
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