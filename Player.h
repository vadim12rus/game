#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Texture.h"

struct PlayerSound
{
	sf::SoundBuffer soundShotgunShotBuffer;
	sf::Sound soundShotgunShot;

	sf::SoundBuffer soundM4A1ShotBuffer;
	sf::Sound soundM4A1Shot;

	void LoadingFromFileSound();
};

enum struct Arms
{
	SHOTGUN,
	M4A1
};

enum struct Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct Player
{
	sf::Sprite playerSprite;

	Direction direction;

	sf::Vector2f mousePosition;

	float currentFrame;
	float countFrame;

	bool isShot;
	Arms weapon;
	PlayerSound playerSound;
};

void InitializePlayer(Player & player, TextureGame & texture);
void HandlePlayerKeyPress(const sf::Event::KeyEvent &event, Player &player);
void HandlePlayerKeyRelease(const sf::Event::KeyEvent &event, Player &player);
void UpdatePlayer(Player &player, float elapsedTime);
void UpdateMousePosition(sf::RenderWindow &window, sf::Vector2f &mousePosition);
void InitializePlayerSound(Player &player);