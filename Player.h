#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"

enum struct Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT,
};

struct Player
{
	sf::Sprite playerSprite;
	Direction direction;
	sf::Vector2f mousePosition;
};

void InitializePlayer(Player & player, TextureGame & texture);
void HandlePlayerKeyPress(const sf::Event::KeyEvent &event, Player &player);
void HandlePlayerKeyRelease(const sf::Event::KeyEvent &event, Player &player);
void UpdatePlayer(Player &player, float elapsedTime);
void UpdateMousePosition(sf::RenderWindow &window, sf::Vector2f mousePosition);