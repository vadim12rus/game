#include "stdafx.h"
#include "Texture.h"

void TextureGame::LoadingFromFileTexture()
{
	playerTexture.loadFromFile("resources/images/player.png");
	cursorTexture.loadFromFile("resources/images/cursor_aim_min.png");
}
