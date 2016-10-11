#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Texture.h"
#include <vector>


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

enum CountFrameThePlayer
{
	CF_STAND = 20,
	CF_RUN = 16,
	CF_RUN_SHOT_SHOTGUN = 20,
	CF_STAND_SHOT_M4A1 = 5,
	CF_RUN_SHOT_M4A1 = 12,
};

enum struct Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct Bullet
{
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f direction;
	float rotation;
	float speed = 2500;
};


struct Player
{
	sf::Sprite playerSprite;

	Direction direction;

	sf::Vector2f mousePosition;

	float currentFrame;
	int countFrame;

	bool isShot;
	Arms weapon;
	PlayerSound playerSound;

	sf::Sprite bulletSprite;
	std::vector<Bullet> bullets;

	float shootingTime;
};

void InitializePlayer(Player & player, TextureGame & texture);
void HandlePlayerKeyPress(const sf::Event::KeyEvent &event, Player &player);
void HandlePlayerKeyRelease(const sf::Event::KeyEvent &event, Player &player);
void UpdatePlayer(Player &player, float elapsedTime);
sf::Vector2f GetMousePosition(sf::RenderWindow &window);
void InitializePlayerSound(Player &player);
void UpdateBullet(Player &player, float elapsedTime);